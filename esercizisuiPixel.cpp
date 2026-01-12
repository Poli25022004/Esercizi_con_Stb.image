#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>

int main()
{
    int width, height, channels;
    unsigned char* immagine = stbi_load("Bianco.png", &width, &height, &channels, 0);
    if (!immagine) {
        printf("Immagine non trovata!\n");
        return 1;
    }

    for (int y = 0; y < height; y++) {
        if (y % 10 == 0) {
            for (int x = 0; x < width; x++) {
                int indice = (y * width + x) * channels;
                for (int c = 0; c < channels; c++) {
                    immagine[indice + c] = 255 - immagine[indice + c];
                }
            }
        }
    }

    if (!stbi_write_png("output.png", width, height, channels, immagine, width * channels)) {
        printf("Errore nel salvare l'immagine\n");
    }

    stbi_image_free(immagine);
    return 0;
}
