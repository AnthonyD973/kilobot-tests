file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

set(AVR_LDEXTRAFLAGS " -Wl,-section-start=.led=0x2001")
kilobot_add_executable(read_flash_data ${files})
set(AVR_LDEXTRAFLAGS "")