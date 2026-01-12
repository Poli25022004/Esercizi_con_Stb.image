#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>

int main()
{
    int width, height, channels;

    unsigned char* img = stbi_load("ombrello.png", &width, &height, &channels, 4);
    if (!img)
        return 1;

    int pixelCount = width * height;

    for (int i = 0; i < pixelCount; i++)
        img[i * 4 + 3] = 128;

    stbi_write_png("output.png", width, height, 4, img, width * 4);

    stbi_image_free(img);
    return 0;
}
