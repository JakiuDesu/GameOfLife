#ifndef WRITE_H
#define WRITE_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "check.h"
#include "makebit.h"

/*
Dodatkowe
//wypisanie pierwszej planszy
void first(char* znak, int wysok, int szerok, int** tabela) {
	int i = 0, j = 0;
	for (i = 0; i < wysok; i++) {
		for (j = 0; j < szerok; j++) {
			printf("%c", znak[tabela[i][j]]);
		}
		printf("\n");
	}
}
*/

//zapisywanie do pliku
void savetofile(FILE* f, int w, int s, int** t) {
	fprintf(f, "%d %d\n", w, s);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < s; j++) {
			fprintf(f, "%d", t[i][j]);
		}
		fprintf(f, "\n");
	}
}

//generowanie kolejnych plansz i zapisywanie ich do bmp
void writebmp(int** tabela, int szerok, int wysok, int iter) {
	int i, j, k, l, ile, flag;
	char buf[12];
	char znaki[2] = { '_', '#' };
	printf("Podaj liczbe iteracji do podejrzenia:\n");
	scanf("%d", &ile);
	int* zobacz = malloc(ile * sizeof(int));
	printf("Podaj na ktorych iteracjach chcesz sie zatrzymac:\n");
	for (i = 0; i < ile; i++) {
		scanf("%d", &zobacz[i]);
	}
	snprintf(buf, 12, "test%d.bmp", 0);
	makebit(buf, tabela, szerok, wysok);
	for(i = 1; i <= iter; i++) {
		init(tabela, wysok, szerok);
		for (j = 0; j < wysok; j++) {
			for (k = 0; k < szerok; k++) {
				check(tabela, wysok, szerok, j, k);
			}
		}
		change(tabela);
		for (l = 0; l < ile; l++) {
			if (zobacz[l] == i) {
				for (j = 0; j < wysok; j++) {
					for (k = 0; k < szerok; k++) {
						printf("%c", znaki[tabela[j][k]]);
					}
					printf("\n");
				}
				printf("Zapisac? 1 - Tak, 0 - Nie\n");
				scanf("%d", &flag);
				if (flag) {
					char filename[20];
					snprintf(filename, sizeof(filename), "iter%d.txt", i);
					puts(filename);
					FILE* out = fopen(filename, "w");
					savetofile(out, wysok, szerok, tabela);
					fclose(out);
				}
			}
		}
		snprintf(buf, 12, "test%d.bmp", i);
		makebit(buf, tabela, szerok, wysok);
	}
}


#endif
