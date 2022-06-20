cmake_minimum_required(VERSION 3.16)
if(${CMAKE_VERSION} VERSION_LESS 3.16)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.16)
endif()
################################################################################
#    PROJECT NAME
################################################################################
project("test")

################################################################################
#    SUBDIRECTORIES
################################################################################
MACRO(SUBDIRLIST result curdir)
    # Find all children whose name is started without "lib"
    file(GLOB children "${curdir}/*")
    set(dirlist "")
    foreach (child ${children})
        if(IS_DIRECTORY ${child})
            list(APPEND dirlist ${child})
        endif()
    endforeach()
    file(GLOB libs "${curdir}/lib*")
    foreach(item ${libs})
        if(IS_DIRECTORY ${item})
            get_filename_component(full_path ${item} ABSOLUTE)
            list(REMOVE_ITEM dirlist "${full_path}")
        endif()
    endforeach()
    file(GLOB test_utils "${curdir}/utils*")
    foreach(item ${test_utils})
        if(IS_DIRECTORY ${item})
            get_filename_component(full_path ${item} ABSOLUTE)
            list(REMOVE_ITEM dirlist "${full_path}")
        endif()
    endforeach()
    set(${result} ${dirlist})
ENDMACRO()
################################################################################
#    ADD SUBDIRECTORIES
################################################################################
SUBDIRLIST(subdirectories ${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdirectory ${subdirectories})
    add_subdirectory(${subdirectory})
endforeach()
