#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <iomanip>
#include "Battlemage.h"
#include "Enemy.h"
#include "Interface.h"
#include "PlaySequence.h"
#include "FileFunctions.h"

using namespace std;

void StartScreen()
{
	system("cls");
	cout << ">------------------------<" << endl;
	cout << ">------------------------<" << endl;
	cout << ">=== BATTLEMAGE ARENA ===<" << endl;
	cout << ">------------------------<" << endl;
	cout << ">------------------------<" << endl;
	cout << endl;
	cout << setw(30) << left << "Created by OlfOlak" << endl;
	system("pause");
}

void WinScreen()
{
	system("cls");
	cout << ">------------------------<" << endl;
	cout << ">======YOU HAVE WON======<" << endl;
	cout << ">==YOU ARE NEW CHAMPION==<" << endl;
	cout << ">------------------------<" << endl;
	cout << ">------------------------<" << endl;
	cout << endl;
	system("pause");
}
	

