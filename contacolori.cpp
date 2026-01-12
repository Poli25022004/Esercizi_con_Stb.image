#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>

int main()
{
    int w, h, ch;
    unsigned char* img = stbi_load("bestemmia.png", &w, &h, &ch, 3);
    if (!img) {
        printf("Errore: %s\n", stbi_failure_reason());
        return 1;
    }

    long long red = 0, green = 0, blue = 0, uguali = 0;

    int pixels = w * h;

    for (int i = 0; i < pixels; i++) {
        unsigned char R = img[i * 3 + 0];
        unsigned char G = img[i * 3 + 1];
        unsigned char B = img[i * 3 + 2];

        if (R > G && R > B)
            red++;
        else if (G > R && G > B)
            green++;
        else if (B > R && B > G)
            blue++;
        else
            uguali++;
    }

    printf("Totale pixel: %d\n", pixels);
    printf("pixel rossi: %lld\n", red);
    printf("pixel verdi: %lld\n", green);
    printf("pixel blu: %lld\n", blue);
    printf("Uguali: %lld\n",uguali);

    stbi_image_free(img);
    return 0;
}
