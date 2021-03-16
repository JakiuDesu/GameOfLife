#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"

int** Matrix(int wys, int szer, FILE* in) {
	int** MatrixMapa = (int**)malloc(sizeof(int*) * wys);
	int i;
	int j;
	int c;
	for (i = 0; i < wys; i++)
		MatrixMapa[i] = (int*)malloc(szer * sizeof(int));

	for (i = 0; i < wys; i++) {
		for (int j = 0; j < szer;) {
			c = fgetc(in);
			if (c == '\n')
				;
			else {
				MatrixMapa[i][j] = c - '0';
				j++;
			}
		}
	}
	for (i = 0; i < wys; i++) {
		for (j = 0; j < szer; j++) {
			printf("%i", MatrixMapa[i][j]);
		}
	}
	return MatrixMapa;
}

#endif