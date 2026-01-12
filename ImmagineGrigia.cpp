#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>

void Grigio(unsigned char* img, int w, int h) {
    int pixel = w * h;
    for (int i = 0; i < pixel; i++) {
        unsigned char* p = img + i * 3;

        unsigned char gray =
            (unsigned char)(0.299f * p[0] +
                0.587f * p[1] +
                0.114f * p[2]);

        p[0] = gray;
        p[1] = gray;
        p[2] = gray;
    }
}

int main() {
    int width, height, channels;

    unsigned char* img = stbi_load("images.jpg", &width, &height, &channels, 3);

    if (!img) {
        printf("Errore nel caricare l'immagine\n");
        return 1;
    }

    Grigio(img, width, height);

    if (!stbi_write_jpg("output.jpg", width, height, 3, img, 100)) {
        printf("Errore nel salvare l'immagine\n");
    }

    stbi_image_free(img);
    return 0;
}
