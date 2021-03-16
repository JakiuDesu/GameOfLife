#ifndef CHECK_H
#define CHECK_H
#include <stdlib.h>

void init(int* tab, int w, int h) {
	vekt* v;
	int length = 0; // ca³a wielkoœæ
	int size = 0; // iloœæ zmiennych w œrodku
	int sum;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			length += tab[i][j];
		}
	}
	length *= 9;
	v = (vekt*)malloc(length * sizeof(vekt));
}

void resize() {
	length *= 2;
	v = (vekt*)realloc(p, length * sizeof(vekt));
	//TO-DO zmieniæ na temp = realloc w ifie by zapobiec wycieku pamiêci
}

void check(int* tab, int w, int h) {
	sum = 0;
	for (int i = w - 1; i <= w + 1; i++) {
		for (int j = h - 1; j <= h + 1; j++) {
			if (i != -1 && j != -1 && i != w && j != h) {
				sum += tab[i][j]
			}
		}
	}
	if (size == length) {
		resize();
	}
	if (tab[i][j] == 1 && (sum != 2 && sum != 3)) {
		vekt[size].x = i;
		vekt[size].y = j;
		vekt[size].wart = 0;
		size++;
	}
	else if (tab[i][j] == 0 && (sum == 3) {
		vekt[size].x = i;
			vekt[size].y = j;
			vekt[size].wart = 1;
			size++;
	}
}

void change(int* tab) {
	for (int i = 0; i < size; i++) {
		tab[vekt[i].x][vekt[i].y] = vekt[i].wart;
	}
	release();
}

void release() {
	free(v);
	v = NULL;
}

#endif