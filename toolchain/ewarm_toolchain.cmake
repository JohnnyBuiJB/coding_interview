set(CMAKE_SYSTEM_NAME Generic)
set(EW_ROOT_DIR "C:/Program Files (x86)/IAR Systems/Embedded Workbench 8.2/arm/bin")
set(CPU_FLAGS "--cpu ARM9E")

SET(CMAKE_C_COMPILER "${EW_ROOT_DIR}/bin/iccarm.exe -Wall -O3 ${CPU_FLAGS} --dlib_config normal" CACHE STRING "Set C compiler")
SET(CMAKE_CXX_COMPILER "${EW_ROOT_DIR}/bin/iccarm.exe -Wall -O3 ${CPU_FLAGS} --dlib_config normal" CACHE STRING "Set CXX compiler")
SET(CMAKE_ASM_COMPILER "${EW_ROOT_DIR}/bin/iasmarm.exe -Wall -O3 ${CPU_FLAGS}" CACHE STRING "Set ASM compiler")

set(LINKER_SCRIPT "${EW_ROOT_DIR}/config/linker/ST/str91xFx44.icf")
set(CMAKE_C_LINK_FLAGS "--semihosting --config ${LINKER_SCRIPT}")
set(CMAKE_CXX_LINK_FLAGS "--semihosting --config ${LINKER_SCRIPT}")

if(${ENABLE_DEBUG})
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  SET(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -g")
endif()
