/*
@file image_creator.hpp
@brief The method to convert a completed QR code to a PNG image. Utilizes stb_image_write.h from `nothings`. Link in README.md.
@author Jacob West
@date 09-28-26
@version 0.1
*/

#pragma once

// PURPOSE
// - Define the image size
// - Pass in the QR code bitstring?
// - Output to the output folder

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <string>

/*
@brief Four options for sizes of the output image in pixels.
Small = 150 x 150
Medium = 300 x 300
Large = 500 x 500
XLarge = 1000 x 1000
*/
enum ImageSize : uint16_t
{
    Small = 200,
    Medium = 300,
    Large = 500,
    XLarge = 1000
};

/*
@brief A method to convert a QR code bitstring into a PNG of a desirable size.

@param[in] p_pixels A pointer to the container holding the pixel data created by the QR code generator.
@param[in] size The number of elements within the container that p_pixels points to
@param[in] img_size A value from the ImageSize enum (found in image_creator.hpp) to note the specific size you want to output the image to.
! I need to define a minimum image size for this to take.
! I think that I also should define specific sizes; maybe I need an Enum to note the sizes that are available to output into.
@param[in] output_name A string noting the output name for the image.

@note This function will always output in the current directory to an `output` folder.

@return true on success, false on failure.

@code
bool status = output_qr_to_png(400);
@endcode
*/
bool output_qr_to_png(uint8_t *p_pixels, const size_t pixel_size, const ImageSize img_size, const std::string output_name)
{
    // stbi_write_png parameters:
    // 1. File path
    // 2. Image width
    // 3. Image height
    // 4. Number of color channels (RGB = 3)
    // 5. Pointer to raw pixel data
    // 6. Row stride in bytes (width * channels)

    std::string filename_str = "output/" + output_name + ".png";
    const char *filename = filename_str.c_str();

    const int channels = 1; // I only need a single channel for a basic QR code, but I can turn this to 3 for RGB

    // Iterate over the pointer; convert 1 to white and 0 to black
    for (size_t i = 0; i < pixel_size; ++i)
    {
        *(p_pixels + i) *= 255;
    }

    // Output
    return stbi_write_png(filename, img_size, img_size, channels, p_pixels, img_size * channels);
}

// ! The code below here is from an implementation where I had RGB as possible channels. For the simple implementation, I will only output in black and white, however I may want this in the future.
// // Dynamically allocate memory for pixel data (width * height * channels)
// uint8_t pixels[width * width * channels];

// // Loop through every pixel to draw the image
// for (int x = 0; x < width; ++x)
// {
//     for (int y = 0; y < width; ++y)
//     {
//         // Calculate the index
//         int idx = (y * width + x) * channels;

//         // Draw a black box
//         if (x > 150 && x < 250 && y > 150 && y < 250)
//         {
//             pixels[idx] = 0; // Red
//             // pixels[idx + 1] = 0; // Green
//             // pixels[idx + 2] = 0; // Blue
//         }
//         else
//         {
//             pixels[idx] = 255; // Red
//             // pixels[idx + 1] = 255; // Green
//             // pixels[idx + 2] = 255; // Blue
//         }
//     }
// }

// // Save the image data as a PNG
// std::string filename_str = "output/" + output_name + ".png";
// const char *filename = filename_str.c_str();

// uint8_t *p_pixels = pixels;

// int success = stbi_write_png(filename, width, width, channels, p_pixels, width * channels);

// if (success)
// {
//     return true;
// }
// else
// {
//     std::cerr << "Failed to write PNG file." << std::endl;
//     return false;
// }