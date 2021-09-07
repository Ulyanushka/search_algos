#pragma once
#include <iostream>

using namespace std;

int lineSearch(int* ar, int key, int arSize)
{
	for (int i = 0; i < arSize; i++)
		if (ar[i] == key)
			return i;
	return -1;
}

int binarySearch(int* sortAr, int key, int arSize)
{
	int left = 0;
	int mid = 0;
	int right = arSize;
	while (left <= right)
	{
		mid = (left + right) / 2;

		if (key < sortAr[mid])
			right = mid - 1;
		else if (key > sortAr[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

int interpolSearch(int* sortAr, int key, int arSize)
{
	int left = 0;
	int mid = 0;
	int right = arSize - 1;

	while (sortAr[left] < key && sortAr[right] > key
		&& sortAr[left] != sortAr[right])
	{
		mid = left + ((key - sortAr[left]) * (right - left)
			/ (sortAr[right] - sortAr[left]));
		if (sortAr[mid] < key)
			left = mid + 1;
		else if (sortAr[mid] > key)
			right = mid - 1;
		else
			return mid;
	}
	if (sortAr[left] == key) return left;
	if (sortAr[right] == key) return right;
	return -1;
}

int eratosthenSearch(int stopNum)
{
	cout << "num ver: ";
	int* ar = new int[stopNum + 1];
	for (int i = 0; i < stopNum + 1; i++)
		ar[i] = i;

	for (int i = 2; i * i < stopNum + 1; i++)
		if (ar[i])
			for (int j = i * i; j < stopNum + 1; j += i)
				ar[j] = 0;

	for (int i = 2; i < stopNum; i++)
		if (ar[i])
			cout << ar[i] << ' ';

	cout << endl << endl;
	delete[] ar;
	return 0;
}

int bool_EratosthenSearch(int stopNum)
{
	cout << "bool ver: ";
	bool* ar = new bool[stopNum + 1];
	for (int i = 2; i * i < stopNum + 1; i++)
		ar[i] = true;

	for (int i = 2; i * i < stopNum + 1; i++)
		if (ar[i])
			for (int j = i * i; j < stopNum + 1; j += i)
				ar[j] = false;

	for (int i = 2; i < stopNum; i++)
		if (ar[i])
			cout << i << ' ';

	cout << endl << endl;
	delete[] ar;
	return 0;
}