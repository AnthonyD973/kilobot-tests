#include <kilolib.h>
#include <avr/pgmspace.h>

#define LED_SECTION_START 0x2000


#define OFF     0
#define RED     1
#define GREEN   2
#define BLUE    4
#define YELLOW  RED + GREEN
#define MAGENTA RED + BLUE
#define CYAN    GREEN + BLUE
#define WHITE   RED + GREEN + BLUE

#define TBL_SZ 8

// Place that table in the ".led" section, which
// we will configure to be in the flash at address LED_SECTION_START.
__attribute__((section(".led")))
const char my_str[TBL_SZ] = { RED, GREEN, BLUE, OFF, YELLOW, MAGENTA, CYAN, WHITE };

/**
 * @brief Set the LED's color.
 */
void led(char color) {
    set_color(RGB(
        color & 1 ? 3 : 0,
        color & 2 ? 3 : 0,
        color & 4 ? 3 : 0
    ));
}

int main() {
    while (1) {
    // Read the colors from the flash and set them.
        for (char i = 0; i < TBL_SZ; ++i) {
            char curr_color = pgm_read_byte(LED_SECTION_START + i);
            led(curr_color);
            delay(500);
        }
    }

    return 0;
}
