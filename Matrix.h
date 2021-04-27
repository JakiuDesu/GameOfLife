#pragma once
#include <stdio.h>
int **Matrix(int wys, int szer, FILE* in);
void freeTab(int** tab, int wys, int szer);