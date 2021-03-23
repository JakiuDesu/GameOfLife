#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Matrix.h"
#include "check.h"
#include <windows.h>
#include "makebit.h"
#include "write.h"

int main(int argc, char** argv) {

	//deklaracja niezbêdnych zmiennych
	int c;
	int data[2] = { 0, 0 };
	int iteracje = 10;
	int i = 0, j = 0, k = 0;
	char znaki[2] = { '_', '#' };
	
	//otworzenie pliku
	FILE* in = fopen(argv[1], "r");

	//sprawdzenie czytanego pliku
	if (in == NULL) {
		fprintf(stderr, "Plik %s nie istnieje!\n", argv[1]);
		exit(1);
	}

	//sprawdzenie argumentu iteracji
	argc > 2 ? iteracje = atoi(argv[2]) : printf(" Brak ilosci iteracji!\n");

	//czytanie wymiarów macierzy
	fscanf(in, "%d", &data[0]);
	fscanf(in, "%d", &data[1]);
	fgetc(in);
	int wys = data[0];
	int szer = data[1];

	//przepisanie pocz¹tkowej macierzy
	int** tab = Matrix(data[0], data[1], in);

	//wypisywanie pierwszej planszy
	first(znaki, wys, szer, tab);

	//generowanie kolejnych plansz i zapisywanie ich do bmp
	write(tab, szer, wys, iteracje, znaki);
	

	return 0;
}