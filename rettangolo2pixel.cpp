#define _CRT_SECURE_NO_WARNINGS
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>

constexpr int CH = 3;

inline void pixel(unsigned char* img, int w, int ch, int x, int y, const unsigned char c[3])
{
    int i = (y * w + x) * ch;
    img[i] = c[0];
    img[i + 1] = c[1];
    img[i + 2] = c[2];
}

void cornice(
    unsigned char* img,
    int w,
    int h,
    int ch,
    int x,
    int y,
    int rw,
    int rh,
    const unsigned char c[3],
    int s)
{
    if (!img || ch < 3) return;

    if (x < 0) { rw += x; x = 0; }
    if (y < 0) { rh += y; y = 0; }
    if (x + rw > w) rw = w - x;
    if (y + rh > h) rh = h - y;
    if (rw <= 0 || rh <= 0) return;

    for (int t = 0; t < s; t++)
    {
        for (int i = x; i < x + rw; i++)
        {
            pixel(img, w, ch, i, y + t, c);
            pixel(img, w, ch, i, y + rh - 1 - t, c);
        }

        for (int j = y; j < y + rh; j++)
        {
            pixel(img, w, ch, x + t, j, c);
            pixel(img, w, ch, x + rw - 1 - t, j, c);
        }
    }
}

int main()
{
    int w = 0, h = 0, ch = 0;

    unsigned char* img = stbi_load("sfondo.png", &w, &h, &ch, CH);
    if (!img)
    {
        printf("Errore caricamento\n");
        return 1;
    }

    int rw = w / 2;
    int rh = h / 2;
    int x = (w - rw) / 2;
    int y = (h - rh) / 2;

    unsigned char rosso[3] = { 255, 0, 0 };

    cornice(img, w, h, CH, x, y, rw, rh, rosso, 2);

    if (!stbi_write_png("output.png", w, h, CH, img, w * CH))
        printf("Errore salvataggio\n");

    stbi_image_free(img);
    return 0;
}
