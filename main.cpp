/*
@file main.cpp
@brief A CLI tool to convert a URL into a QR code, output as a PNG.
@author Jacob West
@date 09-28-26
@version 0.1
*/

// NOTE: The size of a QR code depends on it's LEVEL, which can be from 1 - 40.
// width = 17 + (4 * level)
// I'm not sure how we're supposed to decide on which level to use; do we default to 40, or do we fall back to the minimum satisfactory level?
// The size of these, regardless of level, will always be ODD. I think it's easy enough to translate that from odd sizes to even ones.
// Largest size = 177 x 177 = 31329 pixels
// So the smallest size is 177 x 177. I think the sizes will entirely depend on the scaling factor. Like 1:2x2, 1:3x3, etc.

// RECOMMENDED SIZES: 150 x 150 is the recommended minimum for any QR code. Ideal on digital is about 240 x 240 or higher at 72 DPI (not really in my control I don't think)

// 177 * 2 = 354, so small 354 x 354 could work. Can I reach that from every level with some scaling factor?
// Factors of 354: 1, 2, 3, 6, 59, 118, 177, and 354
// 354 / 2 = 177 - 17 = 160 / 4 = 40 (level 40)
// 354 / 3 = 118 - 17 = 111 / 4 = 2.775 (level 2.775, I don't think this rounds)
// 354 / 6 = 59 - 17 = 42 / 4 = 10.5 (level 10.5, no rounding)
// 354 / 59 = 6 X
// 354 / 118 = 3 X
// 354 / 177 = 2 X

// So how do we scale these if we aren't doing it uniformly? What do I put as my minimum size? I don't want the size of the squares to be irregular.

#include <iostream>
#include "image_creator.hpp"

int main()
{
    const int level = 1;
    const size_t num_pixels = (17 + (4 + level)) * (17 + (4 * level));
    uint8_t pixels[num_pixels];
    uint8_t *p_pixels = pixels;
    bool success = output_qr_to_png(p_pixels, num_pixels, ImageSize::Small, "test");

    if (!success)
    {
        std::cerr << "Failed to write PNG file." << std::endl;
        return 1;
    }

    return 0;
}
