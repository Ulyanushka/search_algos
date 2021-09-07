#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

#include "algos.h"
#include "under_string_fail.h"

using namespace std;

void printAr(int* ar, int arSize)
{
	for (int i = 0; i < arSize; i++)
	{
		cout << setw(4) << ar[i];
		if (!((i + 1) % 10))
			cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int arSize = 50;
	int ar[arSize];
	int sortAr[arSize];
	
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < arSize; i++)
	{
		ar[i] = 1 + rand() % 50;
		sortAr[i] = 1 + rand() % 50;
	}
	sort(sortAr, sortAr + arSize);

	cout << "ar:" << endl;
	printAr(ar, arSize);
	cout << "ar1:" << endl;
	printAr(sortAr, arSize);

	int key = 0;
	int elemPosition = -1;
	int choice = 0;

	while (1)
	{
		cout << "What sort?\n0-exit;\n1-line;\n" <<
			"2-bin (for sorted ar);\n3-interpol (for sorted ar);\n"
			<< "4-eratosthen (type upper stopnum);\n" << 
			"5-search for the understring in the string;\n" << endl;
		cin >> choice;
		if (choice == 0) return 0;

		if (choice == 4)
		{
			cout << "Stopnum? ";
			cin >> key;
		}
		else
		{
			cout << "What num to search? ";
			cin >> key;
		}

		switch (choice)
		{
		case 1:
			elemPosition = lineSearch(ar, key, arSize);
			break;
		case 2:
			elemPosition = binarySearch(sortAr, key, arSize);
			break;
		case 3:
			elemPosition = interpolSearch(sortAr, key, arSize);
			break;		
		case 4:
			eratosthenSearch(key);
			bool_EratosthenSearch(key);
			elemPosition = -2;
			break;
		default:
			elemPosition = lineSearch(ar, key, arSize);
			break;
		}

		if (elemPosition >= 0)
		{
			cout << key << " has "
				<< elemPosition << " position\n" << endl;
		}
		else if (elemPosition == -1)
			cout << "no such element!\n" << endl;
	}
}