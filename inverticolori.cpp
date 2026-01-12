#define _CRT_SECURE_NO_WARNINGS

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>

void Inverti(unsigned char* img, int width, int height, int channels)
{
    int total = width * height * channels;
    for (int i = 0; i < total; i++) {
        img[i] = (unsigned char)(255 - img[i]);
    }
}

int main()
{
    int width, height, channels;

    unsigned char* img = stbi_load("immagine.png", &width, &height, &channels, 0);

    if (!img) {
        printf("Errore nel caricare l'immagine\n");
        return 1;
    }
  
    Inverti(img, width, height, channels);

    if (!stbi_write_png("output.png", width, height, channels, img, width * channels))
    {
        printf("Errore nel salvare l'immagine\n");
    }

    stbi_image_free(img);
    return 0;
}
