#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"

//przepisanie poczatkowej macierzy

int** Matrix(int wys, int szer, FILE* in) {

	//alokacja pamieci

	int** MatrixMapa = (int**)malloc(sizeof(int*) * wys);
	int i;
	int j;
	int c;
	for (i = 0; i < wys; i++)
		MatrixMapa[i] = (int*)malloc(szer * sizeof(int));


	//przepisanie macierzy z pliku

	for(i = 0; i < wys; i++) {
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

	return MatrixMapa;
}

#endif