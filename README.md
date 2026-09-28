REQUIREMENTS:

- 4 levels of data recovery: Low (L), Medium (M), Quartile (Q), High (H)
- Latin-1 encoded characters (idk how to handle if there are characters that fall outside of it)
- Numbers up to 7089
- Kanji?
- Sizes: From version 1 to 40.
- I want to be able to define the image size (so I can use whatever version but make it big enough to be visual) and have the program handle figuring out all the pixels correctly.
  -- stb_image_write.h header? https://github.com/nothings/stb I'm thinking that we create all of them as PNG or JPEG, whatever will give the smallest file sizes.

NEEDS:

- I need to find some C++ simple image generation library, or roll my own simple one. I only need it to output pixels in a fixed size.
