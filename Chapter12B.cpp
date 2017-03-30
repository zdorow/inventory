// Chapter12B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
const int NAME_SIZE = 21, DATE_SIZE = 11, ARRAY_SIZE = 6;
struct items
{
	char name[NAME_SIZE];
	char date[DATE_SIZE];
	int quant;
	double whole, retail;
};
int main()
{
	int quant_array[ARRAY_SIZE];
	double whole_array[ARRAY_SIZE];
	double retail_array[ARRAY_SIZE];
	items invent;
	fstream inventoryFile("C:\\temp\\inventoryFile.dat", ios::in | ios::binary);
	inventoryFile.read(reinterpret_cast<char *>(&invent), sizeof(invent));
	int count;
	for (count = 0; count < 5; count++) {
		quant_array[count] = invent.quant;
		whole_array[count] = invent.whole * invent.quant;
		retail_array[count] = invent.retail * invent.quant;
		inventoryFile.read(reinterpret_cast<char *>(&invent), sizeof(invent));
	}

	cout << "Now calculating data from the file.\n\n";
	cout << "Total wholesale value is: ";
	double sum1 = 0, sum2 = 0;
	for (count = 0; count < 5; count++)
	{
		sum1 += whole_array[count];
	}
	cout << sum1 << "\n";
	cout << "Total retail value is: ";
	for (count = 0; count < 5; count++)
	{
		sum2 += retail_array[count];
	}
	cout << sum2 << "\n";
	cout << "Total quantity of items in the inventory: ";
	int sum = 0;
	for (count = 0; count < 5; count++)
	{
		sum += quant_array[count];
	}
	cout << sum << "\n";

	inventoryFile.close();
	cout << "\nDone.\n";
	system("pause");
}