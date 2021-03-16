#ifndef CHECK_H
#define CHECK_H
#include <stdlib.h>
#include "check.h"

void init(int** tab, int w, int h) {
	extern length, size, sum;
	extern vekt* v;
	length = 0; // cała wielkość
	size = 0; // ilość zmiennych w środku
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
	v = (vekt*)realloc(v, length * sizeof(vekt));
	//TO-DO zmieni� na temp = realloc w ifie by zapobiec wycieku pami�ci
}

void check(int** tab, int w, int h, int x, int y) {
	sum = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i != -1 && j != -1 && i != w && j != h) {
				sum += tab[i][j];
			}
		}
	}
	if (size == length) {
		resize();
	}
	if (tab[x][y] == 1 && (sum != 2 && sum != 3)) {
		v[size].x = x;
		v[size].y = y;
		v[size].wart = 0;
		size++;
	}
	else if (tab[x][y] == 0 && (sum == 3)) {
		v[size].x = x;
			v[size].y = y;
			v[size].wart = 1;
			size++;
	}
}

void change(int** tab) {
	for (int i = 0; i < size; i++) {
		tab[v[i].x][v[i].y] = v[i].wart;
	}
	release();
}

void release() {
	free(v);
	v = NULL;
}

#endif