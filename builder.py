import enum
from operator import mod
import os
import re
import json
from shutil import copyfile, rmtree
from os.path import join, abspath, exists, isdir
from os import getcwd, listdir
from distutils.dir_util import copy_tree
import argparse
from config.config import STATIC_ANALYZER_DIR

REGEX_JSON =\
'''

'''

REGEX_MAP = \
{
    "re.DOTALL": re.DOTALL,
    "re.NORMAL": 0,
}

BAR_COLOR_MAP = \
{
    "LightGray": 'black',
    "LightPink": 'red',
    "#FFFF55": 'yellow',
    "LightGreen": 'green'
}
    

COVERAGE_POOL = "tmp"
SUBMODULE_POOL = "submodule"

# def get_child_abspath(name):
#     current_dir = os.path.abspath(os.getcwd())
#     ret = os.path.join(current_dir, name)
#     return ret

def snake_to_pascal(name):
    str = list(name)
    
    str[0] = str[0].upper()
    
    for i,c in enumerate(str):
        if c == '_':
            str[i + 1] = str[i + 1].upper()
    
    for i in range(str.count('_')):
        str.remove('_')
    
    return "".join(str)

class CoverageSummary:
    def __init__(self):
        self.directory = ""
        self.total_statements = 0
        self.covered_statements = 0
        self.total_branches = 0
        self.covered_branches = 0
    def __str__(self):
        return """ Coverage summary:
            directory: %s
            total_statements: %d
            covered_statements: %d
            total_branches: %d
            covered_branches: %d\
        """ % (self.directory,
        self.total_statements,
        self.covered_statements,
        self.total_branches,
        self.covered_branches)

class Parser:
    def __init__(self):
        with open(join(getcwd(), 'regex_lut.json')) as f:
            self.__regex_lut = json.load(f)

    def __str__(self):
        return ''

    def parse_file(self, fname, summary):
        textfile = open(fname, 'r')
        filetext = textfile.read()
        textfile.close()

        ret = {
            "directory": "",
            "entries": []
        }

        entry = {
            "refs": "",
            "fname": "",
            "lines_total": 0,
            "lines_covered": 0,
            "branches_total": 0,
            "branches_covered": 0
        }


        # Find directory name
        matches = re.findall(self.__regex_lut['source_dir']['syntax'], filetext, REGEX_MAP[self.__regex_lut['source_dir']['flags']])
        if matches and type(matches) != tuple:
            ret['directory'] = matches[self.__regex_lut['source_dir']['group_id']['source_dir']]
        else:
            pass
        # Find coverage group
        matches = re.findall(self.__regex_lut['file_coverage']['syntax'], filetext, REGEX_MAP[self.__regex_lut['file_coverage']['flags']])
        for match in matches:
            # Find refs & filename
            found = re.search(self.__regex_lut['refs_fname']['syntax'], match, REGEX_MAP[self.__regex_lut['refs_fname']['flags']])
            if found:
                entry['refs'] = found[self.__regex_lut['refs_fname']['group_id']['refs']]
                entry['fname'] = found[self.__regex_lut['refs_fname']['group_id']['fname']]
            # Find coverage info
            found = re.findall(self.__regex_lut['covered_total']['syntax'], match, REGEX_MAP[self.__regex_lut['covered_total']['flags']])
            if found:
                entry['lines_covered'] = int(found[0][self.__regex_lut['covered_total']['group_id']['covered']])
                entry['lines_total'] = int(found[0][self.__regex_lut['covered_total']['group_id']['total']])
                entry['branches_covered'] = int(found[1][self.__regex_lut['covered_total']['group_id']['covered']])
                entry['branches_total'] = int(found[1][self.__regex_lut['covered_total']['group_id']['total']])
            ret['entries'].append(entry.copy())

        return ret

class HtmlBuilder:
    def __init__(self):
        with open(join(getcwd(), 'template_header.html'), 'r') as f:
            self.__header = f.read()
        with open(join(getcwd(), 'template_body.html'), 'r') as f:
            self.__body = f.read()
        with open(join(getcwd(), 'template_footer.html'), 'r') as f:
            self.__footer = f.read()
        self.__n_files = 0
        
    def build_header(self, summary):
        cov_format = self.__find_cov_format(summary.covered_statements, summary.total_statements, summary.covered_branches, summary.total_branches)
        text_file = open(join(getcwd(), 'coverage.html'), 'w+')
        mystr = self.__header % \
            (summary.covered_statements,
            summary.total_statements,
            cov_format['statement_cov_color'],
            cov_format['statement_cov_text'],
            summary.covered_branches,
            summary.total_branches,
            cov_format['branch_cov_color'],
            cov_format['branch_cov_text'])
        text_file.write(mystr)
        text_file.close()
    def build_body(self, file_info):
        for entry in file_info['entries']:
            self.__n_files += 1
            file_color = 'LightBlue' if (self.__n_files % 2) == 1 else 'LightSteelBlue'
            cov_format = self.__find_cov_format(entry['lines_covered'], entry['lines_total'],
                                                entry['branches_covered'], entry['branches_total'])
            text_file = open(join(getcwd(), 'coverage.html'), 'a')
            mystr = self.__body % \
                (file_color,
                SUBMODULE_POOL + '/' + entry['refs'],
                file_info['directory'] + entry['fname'],
                file_color,
                cov_format['statement_cov_text'] if cov_format['statement_cov_text'] != '-' else '100',
                BAR_COLOR_MAP[cov_format['statement_cov_color']],
                cov_format['statement_cov_color'],
                cov_format['statement_cov_text'],
                cov_format['statement_cov_color'],
                entry['lines_covered'],
                entry['lines_total'],
                file_color,
                cov_format['branch_cov_text'] if cov_format['branch_cov_text'] != '-' else '100',
                BAR_COLOR_MAP[cov_format['branch_cov_color']],
                cov_format['branch_cov_color'],
                cov_format['branch_cov_text'],
                cov_format['branch_cov_color'],
                entry['branches_covered'],
                entry['branches_total'])
            text_file.write(mystr)
            text_file.close()

    def build_footer(self):
        text_file = open(join(getcwd(), 'coverage.html'), 'a')
        text_file.write(self.__footer)
        text_file.close()

    def __find_cov_format(self, covered_statements, total_statements, covered_branches, total_branches):
        INVALID_COV = 200
        DEFAULT_COLOR = 'LightGray'
        statement_cov_percentage = (covered_statements / total_statements * 100) if (total_statements > 0) else INVALID_COV
        branch_cov_percentage = (covered_branches / total_branches * 100) if (total_branches > 0) else INVALID_COV
        statement_cov_color = DEFAULT_COLOR
        branch_cov_color = DEFAULT_COLOR
        if statement_cov_percentage < 75:
            statement_cov_color = 'LightPink'
        elif statement_cov_percentage < 90:
            statement_cov_color = '#FFFF55'
        elif statement_cov_percentage <= 100:
            statement_cov_color = 'LightGreen'
        else:
            pass
        if branch_cov_percentage < 75:
            branch_cov_color = 'LightPink'
        elif branch_cov_percentage < 90:
            branch_cov_color = '#FFFF55'
        elif branch_cov_percentage <= 100:
            branch_cov_color = 'LightGreen'
        else:
            pass
        statement_cov_text = "%.2f" % (statement_cov_percentage) if (statement_cov_percentage != INVALID_COV) else '-'
        branch_cov_text =  "%.2f" % (branch_cov_percentage) if (branch_cov_percentage != INVALID_COV) else '-'
        return {"statement_cov_color": statement_cov_color,
                "branch_cov_color": branch_cov_color,
                "statement_cov_text": statement_cov_text,
                "branch_cov_text": branch_cov_text}

class Copier:
    def copy_coverage(self):
        self.remove_temp()
        os.mkdir(join(getcwd(), COVERAGE_POOL))
        self.remove_submodule()
        os.mkdir(join(getcwd(), SUBMODULE_POOL))
        os.system('find ../build -name "coverage.*.html" -exec cp {} ./submodule \;')
        for folder in listdir(join(getcwd(), '..', 'build', 'test')):
            if isdir(join(getcwd(), '..', 'build', 'test', folder)) and 'CMakeFiles' not in folder and 'all_test' not in folder:
                os.mkdir(join(getcwd(), COVERAGE_POOL, folder))
                copyfile(join(getcwd(), '..', 'build', 'test', folder, 'html/coverage.html'), join(getcwd(), COVERAGE_POOL, folder, 'coverage.html'))
        os.system('rm -f ./coverage.html')
    def remove_temp(self):
        if exists(join(getcwd(), COVERAGE_POOL)):
            rmtree(join(getcwd(), COVERAGE_POOL))
    def remove_submodule(self):
        if exists(join(getcwd(), SUBMODULE_POOL)):
            rmtree(join(getcwd(), SUBMODULE_POOL))

def main():
    copier = Copier()
    summary = CoverageSummary()
    parser = Parser()
    builder = HtmlBuilder()
    copier.copy_coverage()
    file_info = []
    for folder in listdir(join(getcwd(), COVERAGE_POOL)):
        abspath = join(getcwd(), COVERAGE_POOL, folder, "coverage.html")
        if os.path.isfile(abspath):
            info = parser.parse_file(abspath, summary)
            file_info.append(info)
    copier.remove_temp()
    for info in file_info:
        for entry in info['entries']:
            summary.covered_statements += entry['lines_covered']
            summary.total_statements += entry['lines_total']
            summary.covered_branches += entry['branches_covered']
            summary.total_branches += entry['branches_total']
    builder.build_header(summary)
    for info in file_info:
        builder.build_body(info)
    builder.build_footer()

def assert_dir_name(expected, actual, action):
    if exists(expected) and exists(actual) and (abspath(expected) == abspath(actual)):
        pass # Do nothing
    else:
        print("Error path!!!")
        action()
        sys.exit(1)

def create_parser():
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group()
    group.add_argument('-s', '--setup',
                        action='store_true',
                        help='Setup project')
    group.add_argument('--all',
                        action='store_true',
                        help='Build all targets')
    group.add_argument('--allinone',
                        action='store_true',
                        help='Build all tests in one executable')
    parser.add_argument('-l', '--listtargets',
                        action='store_true',
                        help='List all available targets')
    parser.add_argument('-v', '--verbose',
                        action='store_true',
                        help='Enable verbose')
    parser.add_argument('-cov', '--coverage',
                        action='store_true',
                        help='Generate code coverage')
    parser.add_argument('-p', '--perf',
                        action='store_true',
                        help='Run the performance test of the target')
    group.add_argument('-t', '--target',
                        nargs = 1,
                        help='Build specific target')
    group.add_argument('-c', '--clean',
                        action='store_true',
                        help='Clean project')
    group.add_argument('-n', '--new',
                        nargs = 1,
                        help='New module')
    group.add_argument('-d', '--delete',
                        nargs = 1,
                        help='Delete module')
    return parser

def setup_once():
    os.system('cd build; cmake ..')

def clean():
    os.system('rm -rf build; mkdir -p build;')

if __name__ == "__main__":
    parser = create_parser()
    # assert_dir_name('../builder', '../builder', parser.print_help)
    args = parser.parse_args()
    pre_build_cmd = ''
    build_cmd = ''
    post_build_cmd = ''
    
    if args.setup:
        clean()
        setup_once()
    if args.clean:
        clean()
    if args.all or args.allinone:
        setup_once()
        pre_build_cmd += 'cd build; '
        if args.all:
            build_cmd += ' make all'
        if args.allinone:
            build_cmd += ' make ALL_TEST_coverage'
            post_build_cmd += 'open test/all_test/html/coverage.html'
    if args.listtargets:
        if exists(join(getcwd(), 'build', 'test')):
            print('List of test modules:')
            ii = 0
            for folder in sorted(listdir(join(getcwd(), 'build', 'test'))):
                if isdir(join(getcwd(), 'build', 'test', folder)) and 'CMakeFiles' not in folder and 'all_test' not in folder:
                    if '_perf' not in folder:
                        ii += 1
                        print('\t\t\t%d - %s' % (ii, folder))
        else:
            print('The system has not been set up!!!')
    
    if args.delete:
        for mod_name in args.delete:
            rmtree("./test/%s" % mod_name)
            rmtree("./src/%s" % mod_name)
            
    if args.new:
        for mod_name in args.new:
            if os.path.exists("./test/%s" % mod_name):
                rmtree("./test/%s" % mod_name)
                rmtree("./src/%s" % mod_name)
            
            # Replicate template
            copy_tree("./test/sample", "./test/" + mod_name)
            copy_tree("./src/sample", "./src/" + mod_name)
            
            mod_name_pascal = snake_to_pascal(mod_name)
            
            os.rename("./src/%s/sample.cpp" % (mod_name), \
                      "./src/%s/%s.cpp" % (mod_name, mod_name_pascal))
            
            os.rename("./test/%s/Test.cpp" % (mod_name), \
                      "./test/%s/%sTest.cpp" % (mod_name, mod_name_pascal))
            
            test_cmake = "./test/%s/CMakeLists.txt" % (mod_name)

            # Modify build file
            with open(test_cmake,'r+') as f:
                file = f.read()
                
                file = re.sub("module_name \"sample\"", \
                              "module_name \"%s\"" % mod_name, \
                              file)
                
                f.seek(0)
                f.write(file)
                f.truncate()
                
        clean()
        setup_once()
    
    if args.target:
        pre_build_cmd += 'cd build; '
        for target in args.target:
            if args.perf:
                # Generate performance report
                build_cmd += 'make ' + target + '_perf_test_execution' + '; '
            elif args.coverage:
                build_cmd +=  ' make ' + target + '_test_coverage' + '; '
                post_build_cmd += 'open test/' + target + '/html/coverage.html'
            else:
                build_cmd += STATIC_ANALYZER_DIR + ' make ' + target + '_test_execution' + '; '
        
    elif build_cmd:
        if args.verbose:
            build_cmd += ' VERBOSE=1; '
        else:
            build_cmd += '; '
    else:
        pass

    cmd = pre_build_cmd + build_cmd + post_build_cmd
    cmd_stt = 0
    if cmd:
        os.system('find ../build -name "*.gcda" -exec rm {} \;')
        cmd_stt = os.system(cmd)
    elif args.listtargets or args.clean:
        pass
    
    if args.all:
        if cmd_stt == 0:
            main()
            os.system('open coverage.html')
        else:
            copier = Copier()
            copier.remove_temp()
            copier.remove_submodule()
