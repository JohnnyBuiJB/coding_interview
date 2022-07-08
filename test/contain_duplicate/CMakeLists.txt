cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.16)
endif()

################################################################################
#    MODULE NAME
################################################################################
set(module_name "contain_duplicate")

################################################################################
#    PROJECT NAME
################################################################################
project("${module_name}_test")

################################################################################
#    SOURCE FILES
################################################################################
file(GLOB_RECURSE module_source "${root}/src/${module_name}/*.cpp")
file(GLOB_RECURSE test_utils_sources "${root}/test/utils/*.cpp")

set(sources "")

list(APPEND sources ${module_source})
list(APPEND sources ${test_utils_sources})

################################################################################
#    HEADER FILES
################################################################################
file(GLOB_RECURSE module_headers "${root}/src/${module_name}/*.hpp")
file(GLOB_RECURSE test_utils_headers "${root}/test/utils/*.hpp")

set(headers "")

list(APPEND headers ${module_headers})
list(APPEND headers ${test_utils_headers})

################################################################################
#    TESTS
################################################################################
file(GLOB_RECURSE tests "*.cpp")

# Add linker option to generate map file
add_link_options("LINKER:-map,${PROJECT_BINARY_DIR}/output.map")

################################################################################
#    THIRD PARTY INCLUDE DIRS
################################################################################
set (third_party_include_dirs "")
list (APPEND third_party_include_dirs "${root}/third_party/cpputest/include")

################################################################################
#    THIRD PARTY LIBRARIES
################################################################################
set (third_party_library_dirs "")
list (APPEND third_party_library_dirs "${CMAKE_CURRENT_SOURCE_DIR}/../../libs")

set (third_party_libraries "")
list (APPEND third_party_libraries "libCppUTest.a")

################################################################################
#    ADD TARGETS
################################################################################
#---------------------------- Module executable --------------------------------
add_executable (${PROJECT_NAME} ${tests} ${sources})

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
add_custom_target(${PROJECT_NAME}_execution
    COMMAND ${PROJECT_BINARY_DIR}/${PROJECT_NAME}
    DEPENDS ${PROJECT_BINARY_DIR}/${PROJECT_NAME}
)

