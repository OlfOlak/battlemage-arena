#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Battlemage.h"
#include "Enemy.h"
#include "Interface.h"
#include "FileFunctions.h"

using namespace std;

string LineDivider(int &CharCounter, string InputLine)
{
	string temp;
	temp.clear();
	while (InputLine[CharCounter] != ',')
	{
		temp += InputLine[CharCounter];
		CharCounter++;
	}
	CharCounter++;
	return temp;
}

bool SaveNameCheck(string SaveName)
{
	
	fstream File;
	string Line;
	string CompSaveName;

	File.open("Saves.txt", ios::in);
	while (getline(File, Line))
	{
		int i = 0;
		if (Line == "")
		{
			continue;
		}
		CompSaveName = LineDivider(i, Line);
		
		if (SaveName == CompSaveName)
		{
			return 0;
		}
	}
	File.close();
	return 1;
}

string* ArrayCreator(string ExtraLine, int &Counter)
{
	string* SavesTab = nullptr;
	string* tmp;
	string Line;
	fstream SaveFile;

	SaveFile.open("Saves.txt", ios::in);

	while (getline(SaveFile, Line))
	{
		if (Line == "")
		{
			continue;
		}
		else
		{
			Counter++;
			tmp = new string[Counter];
			for (int j = 0; j < Counter - 1; j++)
			{
				tmp[j] = SavesTab[j];
			}
			tmp[Counter - 1] = Line;
			SavesTab = tmp;
		}
	}
	Counter++;
	tmp = new string[Counter];
	for (int j = 0; j < Counter - 1; j++)
	{
		tmp[j] = SavesTab[j];
	}
	tmp[Counter - 1] = ExtraLine;
	SaveFile.close();

	return tmp;
}

string* ArrayCreator2(int &Counter)
{
	
	string* SavesTab = nullptr;
	string* tmp = nullptr;
	string Line;
	fstream SaveFile;

	SaveFile.open("Saves.txt", ios::in);

	while (getline(SaveFile, Line))
	{
		if (Line == "")
		{
			continue;
		}
		else
		{
			Counter++;
			tmp = new string[Counter];
			for (int j = 0; j < Counter - 1; j++)
			{
				tmp[j] = SavesTab[j];
			}
			tmp[Counter - 1] = Line;
			SavesTab = tmp;
		}
	}
	return tmp;
}

void PrintArray(string* ArrayPointer, int ArrayCounter)
{
	string tmp;
	int j = 0;
	cout << "=== LOAD GAME ===" << endl;
	cout << "   " << setw(21) << left << "GameName" 
		<< setw(21) << left << "PlayerName" 
		<< setw(7) << left << "Health" 
		<< setw(5) << left << "Mana" 
		<< setw(9) << left << "Strength" 
		<< setw(11) << left << "MagicPower" 
		<< setw(12) << left << "GameProgress" << endl;
	for (int i = 0; i < ArrayCounter; i++)
	{
		cout << i+1 << ". " << setw(21) << left << LineDivider(j, ArrayPointer[i]);
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(21) << left << tmp;
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(7) << left << tmp;
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(5) << left << tmp;
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(9) << left << tmp;
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(11) << left << tmp;
		tmp = LineDivider(j, ArrayPointer[i]);
		cout  << setw(11) << left << tmp << endl;
		j = 0;
	}
	
	
}

int EnemysCounter()
{
	int Counter = 0;
	string Line;
	fstream File;

	File.open("Enemys.txt", ios::in);
	if (File.good() == true)
	{
		while (File.eof() != 1)
		{
			getline(File, Line);
			if (Line == "")
			{
				continue;
			}
			else
				Counter++;
		}
	}
	return Counter;
}