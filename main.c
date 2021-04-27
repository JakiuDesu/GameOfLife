#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"
#include "check.h"
#include "makebit.h"
#include "write.h"

int main(int argc, char** argv) {

	//deklaracja niezbednych zmiennych
	int wys, szer;
	int iteracje = 10;
	int i = 0, j = 0, k = 0;

	//otworzenie pliku
	FILE* in = fopen(argv[1], "r");

	//sprawdzenie czytanego pliku
	if (in == NULL) {
		fprintf(stderr, "Plik %s nie istnieje!\n", argv[1]);
		exit(1);
	}

	//sprawdzenie argumentu iteracji
	argc > 2 ? iteracje = atoi(argv[2]) : printf("Brak ilosci iteracji! Domyslna wartosc 10.\n");

	//czytanie wymiarów macierzy
	fscanf(in, "%d", &wys);
	fscanf(in, "%d", &szer);
	fgetc(in);

	//przepisanie pocz¹tkowej macierzy
	int** tab = Matrix(wys, szer, in);
	fclose(in);
/*
	Dodatkowe
	//wypisywanie pierwszej planszy
	first(znaki, wys, szer, tab);
*/
	//generowanie kolejnych plansz i zapisywanie ich do bmp
	writebmp(tab, szer, wys, iteracje);

	return 0;
}

