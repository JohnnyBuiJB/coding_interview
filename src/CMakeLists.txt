cmake_minimum_required(VERSION 3.16)
if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.16)
endif()
################################################################################
#    MODULE NAME
################################################################################
# set(module_name "ALL")
################################################################################
#    PROJECT NAME
################################################################################
project("CodingInterview")
################################################################################
#    SUBDIRECTORIES
################################################################################
# set (subdirectories "")
MACRO(SUBDIRLIST result curdir)
    # Find all children whose name is started without "lib"
    file(GLOB children "${curdir}/*")
    set(dirlist "")
    foreach (child ${children})
        if(IS_DIRECTORY ${child})
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    file(GLOB libs "${curdir}/doc*")
    foreach(item ${libs})
        if(IS_DIRECTORY ${item})
            get_filename_component(full_path ${item} ABSOLUTE)
            list(REMOVE_ITEM dirlist "${full_path}")
        endif()
    endforeach()
    set(${result} ${dirlist})
ENDMACRO()
SUBDIRLIST(subdirectories ${CMAKE_CURRENT_SOURCE_DIR})
################################################################################
#    SOURCE FILES
################################################################################
set(sources "")
file(GLOB_RECURSE cpp_sources "${root}/src/*.cpp")
file(GLOB_RECURSE c_sources "${root}/src/*.c")
list(APPEND sources ${cpp_sources})
list(APPEND sources ${c_sources})
################################################################################
#    HEADER FILES
################################################################################
set(headers "")
file(GLOB_RECURSE cpp_headers "${root}/src/*.hpp")
file(GLOB_RECURSE c_headers "${root}/src/*.h")
list(APPEND headers ${cpp_headers})
list(APPEND headers ${c_headers})
################################################################################
#    TESTS
################################################################################
file(GLOB_RECURSE sources "*.cpp")
################################################################################
#    THIRD PARTY INCLUDE DIRS
################################################################################
set (third_party_include_dirs "")
################################################################################
#    THIRD PARTY LIBRARIES
################################################################################
set (third_party_library_dirs "")
set (third_party_libraries "")
################################################################################
#    ADD TARGETS
################################################################################
#---------------------------- Module executable --------------------------------
add_library(${PROJECT_NAME} ${tests} ${sources})
set_target_properties(${PROJECT_NAME} PROPERTIES EXCLUDE_FROM_ALL TRUE)
#---------------------------- Include headers ----------------------------------
set (user_defined_include_dirs "")
foreach (header_file ${headers})
    get_filename_component(dir ${header_file} PATH)
    list (APPEND user_defined_include_dirs ${dir})
endforeach()
list(REMOVE_DUPLICATES user_defined_include_dirs)
target_include_directories(${PROJECT_NAME} PRIVATE ${user_defined_include_dirs} ${third_party_include_dirs})
#---------------------------- Include libraries --------------------------------
target_link_directories(${PROJECT_NAME} PUBLIC "${third_party_library_dirs}")
target_link_libraries(${PROJECT_NAME} PUBLIC "${third_party_libraries}")
#-------------------------------- Code coverage --------------------------------
