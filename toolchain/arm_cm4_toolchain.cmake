########################################################################
# CONFIG TOOLCHAIN                       
########################################################################
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR arm)

# SET(tools "Default toolchain path" CACHE STRING "Set toolchain path" FORCE)
SET(ARM_CPU "cortex-m4" CACHE STRING "Set ARM cpu" FORCE)

SET(CMAKE_C_COMPILER "${tools}/bin/arm-none-eabi-gcc")
SET(CMAKE_CXX_COMPILER "${tools}/bin/arm-none-eabi-g++")
SET(CMAKE_ASM_COMPILER "${tools}/bin/arm-none-eabi-as")
SET(CMAKE_AR "${tools}/bin/arm-none-eabi-gcc-ar")
SET(CMAKE_LINKER "${tools}/bin/arm-none-eabi-ld")

SET(CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> -o <TARGET> <LINK_LIBRARIES> <OBJECTS>")
SET(CMAKE_CXX_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> -o <TARGET> <LINK_LIBRARIES> <OBJECTS>")

SET(CMAKE_C_RESPONSE_FILE_LINK_FLAG "--via ")
SET(CMAKE_C_OUTPUT_EXTENSION .o)
SET(CMAKE_CXX_OUTPUT_EXTENSION .o)
SET(CMAKE_ASM_OUTPUT_EXTENSION .o)

SET(CMAKE_C_CREATE_STATIC_LIBRARY "<CMAKE_AR> -r -s -v <TARGET> <LINK_FLAGS> <OBJECTS>" )
SET(CMAKE_CXX_CREATE_STATIC_LIBRARY "<CMAKE_AR> -r -s -v <TARGET> <LINK_FLAGS> <OBJECTS>" )

set(CPU_DEFS "-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16") #-fsingle-precision-constant -mlong-calls -mthumb-interwork
# set(STD_DEF "-std=gnu99")
set(STD_DEF "")

SET(CMAKE_C_FLAGS "${CPU_DEFS} ${STD_DEF} -O3 -g" CACHE INTERNAL "C compiler common flags")
SET(CMAKE_CXX_FLAGS "${CPU_DEFS} ${STD_DEF} -O3 -g" CACHE INTERNAL "C compiler common flags")
SET(CMAKE_ASM_FLAGS "${CPU_DEFS} ${STD_DEF} -O3 -g" CACHE INTERNAL "ASM compiler common flags")
# SET(CMAKE_EXE_LINKER_FLAGS "-flto" CACHE INTERNAL "linker flags")

# Search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
