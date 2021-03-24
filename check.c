#ifndef CHECK_H
#define CHECK_H
#include <stdlib.h>
#include "check.h"

//inicjalizacja wektora do obliczania stanu komorki
void init(int** tab, int w, int h) {
	extern length, size, sum;
	extern vekt* v;
	length = 0; // cala wielkosc
	size = 0; // ilosc zmiennych w srodku
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			length += tab[i][j];
		}
	}
	length *= 9;
	v = (vekt*)malloc(length * sizeof(vekt));
}

//dostosowanie rozmiaru wektora
void resize() {
	length *= 2;
	v = (vekt*)realloc(v, length * sizeof(vekt));
	//TO-DO zmienic na temp = realloc w ifie by zapobiec wycieku pamieci
}

void check(int** tab, int w, int h, int x, int y) {

	// sasiedztwo wg Moore'a - skanowanie komorek okalajacych, sprawdzanie ich stanu
	sum = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i != -1 && j != -1 && i != w && j != h && !(i == x && j == y)) {
				sum += tab[i][j];
			}
		}
	}
	if (size == length) {
		resize();
	}
	//zasady gry - komorki zywe - aby zmienic zasady otoczenia, zmien warunek "sum"
	if (tab[x][y] == 1 && (sum != 2 && sum != 3)) {
		v[size].x = x;
		v[size].y = y;
		v[size].wart = 0;
		size++;
	}
	//zasady gry - komorki martwe - aby zmienic zasady otoczenia, zmien warunek "sum"
	else if (tab[x][y] == 0 && (sum == 3)) {
		v[size].x = x;
			v[size].y = y;
			v[size].wart = 1;
			size++;
	}
}

//aktualizacja planszy o zmiany w danej iteracji
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