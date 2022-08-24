cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.16)
endif()


project(algorithms  VERSION 1.0
                    DESCRIPTION "Algorithms Practices"
                    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(COMPILE_FLAGS -O0)
################################################################################
#    CONFIGURE ENVIRONMENT PATHS
################################################################################
set(root ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Set root")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/default_toolchain.cmake" CACHE FILEPATH "Set toolchain")

################################################################################
#    CONFIGURE TARGET ARCHITECTURE
################################################################################

################################################################################
#    CONFIGURE OPTIONS
################################################################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

option(CODE_COVERAGE "Code coverage" OFF) # Enable / disable code coverage
option(ENABLE_TEST "Enable test" ON) # Enable / disable testing
if(${CODE_COVERAGE})
    set(ENABLE_TEST ON)
endif()

# Enable / disable debug compiler flag
option(ENABLE_DEBUG "Enable debug" ON)

# Enable / disable matlab engine framework
option(ENABLE_MATLAB_ENGINE "Enable matlab engine" OFF)

# Color report
string(ASCII 27 Esc)
set(ColourReset "${Esc}[m")
set(ColourBold  "${Esc}[1m")
set(Red         "${Esc}[31m")
set(Green       "${Esc}[32m")
set(Yellow      "${Esc}[33m")
set(Blue        "${Esc}[34m")
set(Magenta     "${Esc}[35m")
set(Cyan        "${Esc}[36m")
set(White       "${Esc}[37m")
set(BoldRed     "${Esc}[1;31m")
set(BoldGreen   "${Esc}[1;32m")
set(BoldYellow  "${Esc}[1;33m")
set(BoldBlue    "${Esc}[1;34m")
set(BoldMagenta "${Esc}[1;35m")
set(BoldCyan    "${Esc}[1;36m")
set(BoldWhite   "${Esc}[1;37m")

################################################################################
#    CONFIGURE TOOLCHAIN
################################################################################
include(${CMAKE_TOOLCHAIN_FILE})

################################################################################
#    ADD RECURSIVELY
################################################################################
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")

################################################################################
#    INSTALL
################################################################################

################################################################################
#    POST PROCESSING
################################################################################
