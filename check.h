#pragma once
typedef struct vekt {
	int x, y, wart;
} vekt;

vekt* v;
int size, length, sum;

void init(int** tab, int w, int h);
void resize();
void check(int** tab, int w, int h, int x, int y);
void change(int** tab);
void release();