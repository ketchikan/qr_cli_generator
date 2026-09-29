REQUIREMENTS:

- 4 levels of data recovery: Low (L), Medium (M), Quartile (Q), High (H)
- Latin-1 encoded characters (idk how to handle if there are characters that fall outside of it)
- Numbers up to 7089
- Kanji?
- Sizes: From version 1 to 40.

NEEDS:

- I need to find some C++ simple image generation library, or roll my own simple one. I only need it to output pixels in a fixed size.

USED:

- [stb_image_write.h](https://github.com/nothings/stb/blob/master/stb_image_write.h)

QUESTIONS:

- How do I determine what level to use? Do I just pick 40 as the default level? Do we use the minimum satisfactory level?
- Should I give the CLI the option for how much redundancy to include? There are different levels I could implement.
- How can I go about scaling the images?
- What image sizes should I implement? I'd rather define discrete image sizes rather than a scaling factor.
- I've found that a minimum size that makes sense to me is 354 x 354. How can I efficiently make sure that every level can be scaled up to that minimum size, and then beyond?
  -- IDEA: Like fibbonacchi, can I show that any level can reach essentially some other level via scaling?
  -- There may also be a different minimum size that I need to factor in.
