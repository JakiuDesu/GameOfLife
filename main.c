#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"

int main(int argc, char** argv) {

	int c;
	int data[2];
	int iteracje;

	FILE* in = fopen("table.txt", "r");

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
			data[i] = c;
			i++;
		}
	}
	int wys = data[0];
	int szer = data[1];
	Matrix(data[0], data[1], in);


	return 0;
}