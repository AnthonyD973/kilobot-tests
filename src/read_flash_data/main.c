#include <kilolib.h>
#include <avr/pgmspace.h>

#define LED_SECTION_START 0x2001


#define O  0            // OFF
#define R  1            // Red
#define G  2            // Green
#define B  4            // Blue
#define C (G + B)       // Cyan
#define M (R + B)       // Magenta
#define Y (R + G)       // Yellow
#define W (R + G + B)   // White

#define TBL_SZ 1100

// Place that table in the ".led" section, which
// we will configure to be in the flash at address LED_SECTION_START.
// Take a huge amount of data to make sure we're not placing the whole data in the RAM at once.
__attribute__((section(".led")))
volatile const uint16_t my_str[TBL_SZ] = {
    R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O,
    R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R,
    R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O,
    G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G,
    G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G, G,
    R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O,
    B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B, B,
    R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O, R, G, B, O, C, M, Y, W, O, O,
    O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O,
    O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O,
    O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O };

/**
 * @brief Set the LED's color.
 */
void led(uint16_t color) {
    set_color(RGB(
        color & 1 ? 1 : 0,
        color & 2 ? 1 : 0,
        color & 4 ? 1 : 0
    ));
}

int main() {
    while (1) {
    // Read the colors from the flash and set them.
        for (uint16_t i = 0; i < TBL_SZ; ++i) {
            uint16_t curr_color = pgm_read_word(LED_SECTION_START + sizeof(my_str[0])*i);
            led(curr_color);
            delay(10);
        }
    }

    return 0;
}
