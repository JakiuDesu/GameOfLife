#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"
#include "check.h"
#include <windows.h>

int main(int argc, char** argv) {
	int c;
	int data[2] = { 0, 0 };
	int iteracje = 10;

	FILE* in = fopen(argv[1], "r");

	if (in == NULL) {
		fprintf(stderr, "Plik %s nie istnieje!\n", argv[1]);
		exit(1);
	}

	argc > 2 ? iteracje = atoi(argv[2]) : printf(" Brak ilosci iteracji!\n");

	int i = 0, j = 0, k = 0;
	fscanf(in, "%d", &data[0]);
	fscanf(in, "%d", &data[1]);
	fgetc(in);
	int wys = data[0];
	int szer = data[1];
	int** tab = Matrix(data[0], data[1], in);
	char znaki[2] = { '_', '#' };
	Sleep(3000);
	system("cls");
	for (i = 0; i < wys; i++) {
		for (j = 0; j < szer; j++) {
			printf("%c", znaki[tab[i][j]]);
		}
		printf("\n");
	}
	Sleep(200);
	system("cls");
	for (i = 0; i < iteracje; i++) {
		init(tab, wys, szer);
		for (j = 0; j < wys; j++) {
			for (k = 0; k < szer; k++) {
				check(tab, wys, szer, j, k);
			}
		}
		change(tab);
		for (j = 0; j < wys; j++) {
			for (k = 0; k < szer; k++) {
				printf("%c", znaki[tab[j][k]]);
			}
			printf("\n");
		}
		Sleep(200);
		system("cls");
	}
	
	
	return 0;
}