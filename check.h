#pragma once
typedef struct vekt {
	int x, y, wart;
};

extern vekt v;
extern int size, length, sum;

void init(int* tab, int w, int h);
void resize(vekt v, int length);
void check(int* tab, int w, int h);
void release(vekt v);