#include <kilolib.h>
#include <avr/eeprom.h>

#define OFF     0
#define RED     1
#define GREEN   2
#define BLUE    4
#define YELLOW  RED + GREEN
#define MAGENTA RED + BLUE
#define CYAN    GREEN + BLUE
#define WHITE   RED + GREEN + BLUE

#define TBL_SZ 8

// Place that table in the ".eeprom" section
EEMEM const uint8_t my_str[TBL_SZ] = { WHITE, CYAN, MAGENTA, YELLOW, OFF, BLUE, GREEN, RED };

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
            uint8_t curr_color = my_str[i];
            led(curr_color);
            delay(500);
        }
    }

    return 0;
}
