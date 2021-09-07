#pragma once
#include <iostream>

#include "algos.h"

using namespace std;

int pos(char* s, char* c, int n)
{
	int i, j; // Счетчики для циклов
	int lenC, lenS; // Длины строк

	//Находим размеры строки исходника и искомого
	for (lenC = 0; c[lenC]; lenC++);
	for (lenS = 0; s[lenS]; lenS++);

	for (i = 0; i <= lenS - lenC; i++) // Пока есть возможность поиска
	{
		for (j = 0; s[i + j] == c[j]; j++); // Проверяем совпадение посимвольно
		// Если посимвольно совпадает по длине искомого
		// Вернем из функции номер ячейки, откуда начинается совпадение
		// Учитывать 0-терминатор  ( '\0' )
		if (j - lenC == 1 && i == lenS - lenC && !(n - 1)) return i;
		if (j == lenC)
			if (n - 1) n--;
			else return i;
	}
	//Иначе вернем -1 как результат отсутствия подстроки
	return -1;
}

int under_stringSearch(char* st, char* und)
{
	int lenS = strlen(st);
	int lenU = strlen(und);
	cout << endl;

	for (int i = 0; i < lenS - lenU; i++)
	{
		cout << i << " ";
		for (int j = 0; j < lenU; j++)
		{
			if (und[j] != st[i + j]) break;
			if (j == (lenU - 1)) return i;
		}
	}
	return -1;

	/*
	for (int i = 0; i <= lenS - lenU; ++i)
	{
		for (j = 0; (j < lenS) && (und[j] = st[i + j]); ++j);
		if (j >= lenS) return i;
	}
	*/
	/*
	int eqChars = 0;
	for (int i = 0; i <= lenS - lenU; i++)
	{
		for (int j = 0; j < lenU + 1; j++)
		{
			if (und[j] != st[i + j]) break;
			if (j == lenU) return i;
		}
	}*/
	return -1;
	//s=st, c=under
}