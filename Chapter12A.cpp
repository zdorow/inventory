// Chapter12A.cpp : Inventory Data 
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void ClearInput();
const int NAME_SIZE = 21, DATE_SIZE = 11;
struct items
{
	char name[NAME_SIZE];
	char date[DATE_SIZE];
	int quant;
	double whole, retail;
};
int main()
{
	items invent;
	fstream inventoryFile;
	int count;
	cout << "Opening file...\n";
	inventoryFile.open("C:\\temp\\inventoryFile.dat", ios::out | ios::binary);
	for (count = 0; count < 5; count++)
	{
		cout << "Please input the items name:\n";
		cin.getline(invent.name, NAME_SIZE);
		cout << "Please input the date received in decimal format:\n";
		cin.getline(invent.date, DATE_SIZE);
		cout << "Please input quantity:\n";
		cin >> invent.quant >> fixed >> setprecision(0);
		cout << "Please input the wholesale cost:\n";
		cin >> invent.whole >> setprecision(2);
		cout << "Please input the retail cost:\n";
		cin >> invent.retail >> setprecision(2);
		cout << "Now writing data to the file.\n";
		inventoryFile.write(reinterpret_cast<char *>(&invent), sizeof(invent));
		cout << "Done writing item " << count + 1 << " to the inventory file.\n";
		ClearInput();
	}
	cout << "You have filled out the required inventory.\n" << "Please open the next program to calcualte totals.\n";
	cout << "Now closing the file.\n";
	inventoryFile.close();
	system("pause");
}

void ClearInput() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
