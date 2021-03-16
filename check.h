#pragma once
typedef struct vekt {
	int x, y, wart;
} vekt;

extern vekt* v;
extern int size, length, sum;

void init(int** tab, int w, int h);
void resize();
void check(int** tab, int w, int h);
void release();