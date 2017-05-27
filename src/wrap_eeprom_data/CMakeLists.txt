file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

kilobot_add_executable(wrap_eeprom_data ${files})