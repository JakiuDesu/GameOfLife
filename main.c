#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"

int main(int argc, char** argv) {

	int c;
	int data[2] = { 0, 0 };
	int iteracje;
	int** tab;

	FILE* in = fopen("C:\\Users\\owner\\source\\repos\\GameOfLife\\table.txt", "r");

	if (in == NULL) {
		fprintf(stderr, "Plik %s nie istnieje!\n", argv[1]);
		exit(1);
	}

	argc > 2 ? iteracje = atoi(argv[2]) : printf(" Brak ilosci iteracji!");

	int i = 0;
	while ((c = fgetc(in)) != EOF && c != '\n') {
		if (isspace(c)) {
			;
		}
		else {
			data[i] = c - '0';
			i++;
		}
	}
	int wys = data[0];
	int szer = data[1];
	tab = Matrix(data[0], data[1], in);


	return 0;
}