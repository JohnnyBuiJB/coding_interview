################################################################################
#    CROSS COMPILING
################################################################################
# Target architecture
SET(CMAKE_OSX_ARCHITECTURES "arm64" CACHE STRING "Build architectures for Mac OS X" FORCE)

# Compile options
SET(CMAKE_C_COMPILER "/usr/bin/clang" CACHE STRING "Set C compiler")
SET(CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "Set CXX compiler")

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -arch arm64")
SET(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")

if(${ENABLE_DEBUG})
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")
endif()

if(${CODE_COVERAGE})
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
  SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --coverage")
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

if(${ENABLE_TEST})
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall")
  SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -O0")
else()
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -Wall")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall")
  SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -O0")
endif()

# if(${ENABLE_TEST})
#   SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Dprivate=public")
#   SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Dprivate=public")
#   SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Dprivate=public")
# endif()

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -Wall")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread")
