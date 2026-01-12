#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char* img_src = stbi_load("sfondo.png", &width, &height, &channels, 3);
    if (!img_src) {
        printf("Errore nel caricare l'immagine\n");
        return 1;
    }
    channels = 3;  
    size_t size = width * height * channels;
    unsigned char* img = (unsigned char*)malloc(size);
    if (!img) {
        printf("Errore malloc\n");
        stbi_image_free(img_src);
        return 1;
    }
    memcpy(img, img_src, size);

    stbi_image_free(img_src);
    /*
    int y = height / 2
    for (int x = 0; x < width; x++)
    {
        //gray
        if (channels == 1)
        {
            img[y * width + x] = 0;
        }
        //RGB oppure BGR
        else if (channels == 3)
        {
            img[y * width * 3 + x * 3 + 0] = 0;
            img[y * width * 3 + x * 3 + 1] = 0;
            img[y * width * 3 + x * 3 + 2] = 0;
        }
        else if (channels == 4)
        {
            img[y * width * 4 + x * 4 + 0] = 0;
            img[y * width * 4 + x * 4 + 1] = 0;
            img[y * width * 4 + x * 4 + 2] = 0;
            img[y * width * 4 + x * 4 + 3] = 0;
        }
    }
    */
      int y = height / 2;
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < channels; c++)
            {
            
                img[y * width * channels + x * channels + c] = 0;
            }
        }
        int x = width / 2;
            for (int y = 0; y < height; y++)
            {
                for (int d = 0; d < channels; d++) {
                 
                    img[y * width * channels + x * channels + d] = 0;
                }
            }
    if (!stbi_write_bmp("output.bmp", width, height, channels, img)) {
        printf("Errore nel salvare l'immagine\n");
        free(img);
        return 1;
    }
    free(img);

    printf("Conversione completata: output.bmp\n");
    return 0;
}
