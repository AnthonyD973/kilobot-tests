#include <kilolib.h>
#include <avr/eeprom.h>

#define EEPROM_MY_SECTION_START 0x00

#define O  0            // OFF
#define R  1            // Red
#define G  2            // Green
#define B  4            // Blue
#define C (G + B)       // Cyan
#define M (R + B)       // Magenta
#define Y (R + G)       // Yellow
#define W (R + G + B)   // White

#define TBL_SZ 8

// Place that table in the ".eeprom" section
EEMEM volatile const uint8_t my_str[TBL_SZ] = { W, Y, M, C, O, B, G, R };

/**
 * @brief Set the LED's color.
 */
void led(uint8_t color) {
    set_color(RGB(
        color & 1 ? 3 : 0,
        color & 2 ? 3 : 0,
        color & 4 ? 3 : 0
    ));
}

int main() {

    while (1) {
        // Read the colors from the flash and set them.
        for (uint8_t i = 0; i < TBL_SZ; ++i) {
            eeprom_busy_wait();
            uint8_t curr_color = eeprom_read_byte((const uint8_t*)&my_str[i]);
            led(curr_color);
            delay(500);
        }
    }

    return 0;
}
