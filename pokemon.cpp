#define _CRT_SECURE_NO_WARNINGS

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define canali 3
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <cmath>

#include <cstdio>

bool sono_stesso_colore(unsigned char R1, unsigned char G1, unsigned char B1,
	unsigned char R2, unsigned char G2, unsigned char B2) {
   
    if (R1 == R2 && G1 == G2 && B1 == B2) {
        return true;
    }else {
        return false;
    }
}
void pixel(unsigned char* img, int w, int ch, int x, int y, const unsigned char c[canali])
{
    int i = y * w + x;
    img[i] = c[0];
    img[i + 1] = c[1];
    img[i + 2] = c[2];
}
int main()
{
	int width, height, channels,x,y;
	int width2, height2, channels2;
    float luminosita;
    unsigned char* img1 = stbi_load("pika.bmp", &width, &height, &channels, 0);
	unsigned char* img2 = stbi_load("Charizard.bmp", &width2, &height2, &channels2, 0);

    if (!img1 || !img2) {
        printf("Errore caricamento immagini\n");
        return 1;
    }

    if (width != width2 || height != height2 || channels != channels2)
    {
        printf("Le immagini hanno dimensioni o numero di canali diversi\n");
        stbi_image_free(img1);
        stbi_image_free(img2);
        return 1;
    }

    unsigned char* RGB1 = (unsigned char*)malloc(channels * sizeof(unsigned char));
    unsigned char* RGB2 = (unsigned char*)malloc(channels * sizeof(unsigned char));

    //tutte le dimensioni sono uguali tra le due immagini
    int h = height2;
    int w = width2;
    int chs = channels2;

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            //int rgb = (chs > 3) ? rgb = 3 : rgb = chs;



            //raccolgo i colori
            for (int c = 0; c < chs; c++)
            {
                int indice = y * (w * chs) + (x * chs) + c;

                RGB1[c] = img1[indice];
                RGB2[c] = img2[indice];
            }
            
            //vedo se sono uguali
            bool uguali = true;
            
            for (int c = 0; c < chs; c++)
            {
                if (RGB1[c] != RGB2[c])
                {
                    uguali = false;
                    break;
                }
            }

            if (uguali)
                printf("alla coordinata x %d y %d i pixel sono uguali\n", x, y);
        }
        for (int i = 0; i < channels; i++) {
            if (RGB1[i] > 100) {
                luminosita = sqrt(RGB1[i] * RGB1[i] + RGB1[i + 1] * RGB1[i + 1] + RGB1[i + 2] * RGB1[i + 2]);
                printf("alla coldinata x %d y %d trovato il valore massimo\n", luminosita);
            }
        }
    }

    free(RGB1);
    free(RGB2);

    return 0;
}

