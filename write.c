#ifndef WRITE_H
#define WRITE_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "check.h"
#include <windows.h>
#include "makebit.h"

//wypisanie pierwszej planszy
void first(char* znak, int wysok, int szerok, int** tabela) {
	int i = 0, j = 0;
	Sleep(3000);
	system("cls");
	for (i = 0; i < wysok; i++) {
		for (j = 0; j < szerok; j++) {
			printf("%c", znak[tabela[i][j]]);
		}
		printf("\n");
	}
}

//generowanie kolejnych plansz i zapisywanie ich do bmp
void write(int** tabela, int szerok, int wysok, int iter, char znak[]) {
	int i = 0, j = 0, k = 0;
	char buf[12];
	snprintf(buf, 12, "test%d.bmp", 0);
	makebit(buf, tabela, szerok, wysok);
	Sleep(200);
	system("cls");
	for (i = 0; i < iter; i++) {
		init(tabela, wysok, szerok);
		for (j = 0; j < wysok; j++) {
			for (k = 0; k < szerok; k++) {
				check(tabela, wysok, szerok, j, k);
			}
		}
		change(tabela);
		for (j = 0; j < wysok; j++) {
			for (k = 0; k < szerok; k++) {
				printf("%c", znak[tabela[j][k]]);
			}
			printf("\n");
		}
		snprintf(buf, 12, "test%d.bmp", i + 1);
		makebit(buf, tabela, szerok, wysok);
		Sleep(200);
		system("cls");
	}
}
#endif
