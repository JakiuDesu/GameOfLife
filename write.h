#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
// Dodatkowe: void first(char* znak, int wysok, int szerok, int** tabela);
void write(int** tabela, int szerok, int wysok, int iter);
void savetofile(FILE* f, int w, int s, int** t);