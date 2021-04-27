#include "gifenc.h"

//tworzenie pliku bmp
void makebit(char* filename, int** tab, int w, int h) {
	int i, j, scale = 1;
	while (w * scale < 800 && h * scale < 600)
		scale++;

	ge_GIF* g = ge_new_gif(
		filename,
		w * scale, h * scale,
		(uint8_t[]) {
			0xFF, 0xFF, 0xFF,
			0x00, 0x00, 0x00,	
		},
		2,
		1
	);
	for (i = 0; i < h * scale;i++) {
		for (j = 0; j < w * scale; j++) {
			g->frame[i * w * scale + j] = tab[i/scale][j/scale];
		}
	}
	ge_add_frame(g, 100);
	ge_close_gif(g);
}