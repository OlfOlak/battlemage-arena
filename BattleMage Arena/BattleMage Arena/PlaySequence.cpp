#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <iomanip>
#include <conio.h>
#include "Battlemage.h"
#include "Enemy.h"
#include "Interface.h"
#include "PlaySequence.h"
#include "FileFunctions.h"


using namespace std;

PlaySequence::PlaySequence()
{
	PlaySequenceName = "Game1";
	PlayerName = "Player";
	PlayerHealth = 100;
	PlayerMana = 100;
	PlayerStrength = 10;
	PlayerMagicpower = 10;
	GameProgress = 0;
}

PlaySequence::~PlaySequence()
{
}



bool PlaySequence::MainMenu()
{
	system("cls");
	int MainMenuChoice;

	cout << "--== BATTLEMAGE ARENA ==--" << endl;
	cout << "1. New Game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Credits" << endl;
	cout << "4. Exit" << endl;
	cout << "--==Choice: ";
	cin >> MainMenuChoice;

	switch (MainMenuChoice)
	{
	case 1:
		system("cls");
		cout << "Enter your Battlemages name: " << endl;
		cin >> PlayerName;
		Game();
		return 1;
		break;
	case 2:
		LoadSequence();
		Game();
		system("pause");
		return 1;
		break;
	case 3:
		system("cls");
		cout << "Created by OlfOlak" << endl;
		cout << "https://github.com/OlfOlak" << endl;
		system("pause");
		return 1;
		break;
	case 4:
		system("cls");
		cout << "Press ENTER to leave" << endl;
		return 0;
		break;
	default:
		cout << "Wrong choice number. Enter value 1-4 next time!!" << endl;
		break;
	}
	
}


int PlaySequence::FightSequence(int FightSequenceCounter)
{
	Battlemage BattlemageObj;
	Enemy EnemyObj;
	EnemyObj.LoadEnemy(FightSequenceCounter);

	// Filling BattlemageObj with numbers.
	BattlemageObj.Name = PlayerName;
	BattlemageObj.Health = PlayerHealth;
	BattlemageObj.Mana = PlayerMana;
	BattlemageObj.Strength = PlayerStrength;
	BattlemageObj.MagicPower = PlayerMagicpower;

	// Variables.
	int FightRound = 1;
	int ActionChoice;
	int ArmourCounter = 0;
	int AttackCounter = 0;

	while (true)
	{
		system("cls");
		cout << setw(20) << left << BattlemageObj.Name << "\t" << setw(25) << left << EnemyObj.Name << setw(10) << left << "ROUND: " << FightRound << endl;
		cout << setw(15) << left << "Health: " << BattlemageObj.Health << "\t" << setw(15) << left << "Health: " << EnemyObj.Health << endl;
		cout << setw(15) << left << "Mana: " << BattlemageObj.Mana << "\t" << setw(15) << left << "Armour: " << EnemyObj.Armour << setw(8) << left << " Arm++: " << EnemyObj.ArmourIncrement << endl;
		cout << setw(15) << left << "Strength: " << BattlemageObj.Strength << "\t" << setw(15) << left << "Attack: " << EnemyObj.Attack << setw(8) << left << " Att++: " << EnemyObj.AttackIncrement << endl;
		cout << setw(15) << left << "MagicPower: " << BattlemageObj.MagicPower << endl;
		cout << "-----------------" << endl;
		cout << "ACTIONS: " << endl;
		cout << "1. Sword Attack" << endl;
		cout << "2. Fireball Throw" << endl;
		cout << "3. Sword Parry" << endl;
		cout << "4. Magic Shield" << endl;
		cout << "Your action(1-4): ";
		cin >> ActionChoice;

		switch (ActionChoice)
		{
		case 1:
			BattlemageObj.SwordAttack(EnemyObj);
			ArmourCounter++;
			AttackCounter++;
			EnemyObj.IncrementArmour();
			EnemyObj.IncrementAttack();
			system("pause");
			break;
		case 2:
			if (BattlemageObj.Mana < (30 - BattlemageObj.MagicPower))
			{
				cout << "Not enough MANA!" << endl;
				FightRound--;
				system("pause");
				break;
			}
			else
			{
				BattlemageObj.FireballThrow(EnemyObj);
				ArmourCounter++;
				AttackCounter++;
				EnemyObj.IncrementArmour();
				EnemyObj.IncrementAttack();
				system("pause");
				break;
			}
		case 3:
			BattlemageObj.SwordParry(ArmourCounter, EnemyObj);
			EnemyObj.ReverseArmourIncrements(ArmourCounter);
			system("pause");
			break;
		case 4:
			if (BattlemageObj.Mana < EnemyObj.Attack)
			{
				cout << "Not enough MANA!" << endl;
				FightRound--;
				system("pause");
				break;
			}
			else
			{
				BattlemageObj.MagicResist(AttackCounter, EnemyObj);
				EnemyObj.ReverseAttackIncrements(AttackCounter);
				system("pause");
				break;
			}
		default:
			cout << "Wrong action, choose once more!" << endl;
			system("pause");
		}


		if (BattlemageObj.Health <= 0)
		{
			system("cls");
			cout << "== !YOU LOST! ==" << endl;
			system("pause");
			return 0;
		}
		if (EnemyObj.Health <= 0)
		{
			system("cls");
			cout << "== !YOU WON! ==" << endl;
			system("pause");
			return 1;
		}
		FightRound++;
	}
}


void PlaySequence::SaveSequence(bool Mode)
{
	string SaveLine;
	string* SavesArrayPointer;
	int i = 0;

	if (Mode == 0)
	{

		while (true)
		{
			system("cls");
			cout << "Enter your game's name: ";
			cin >> PlaySequenceName;
			if (SaveNameCheck(PlaySequenceName) == 0)
			{
				cout << "Game of that name already exists. Try diffrent name!" << endl;
				system("pause");
			}
			else
			{
				break;
			}
		}
		SaveLine = PlaySequenceName + "," + PlayerName + "," 
			+ to_string(PlayerHealth) + "," + to_string(PlayerMana) + "," 
			+ to_string(PlayerStrength) + "," + to_string(PlayerMagicpower) + ","
			+ to_string(GameProgress) + ",";
		SavesArrayPointer = ArrayCreator(SaveLine, i);
		
		fstream SaveFile;
		SaveFile.open("Saves.txt", ios::out);
		if (SaveFile.good() == true)
		{
			for (int k = 0; k <= i - 1; k++)
			{
				SaveFile << SavesArrayPointer[k];
				SaveFile << endl;
			}
		}
		else
			cout << "File access error!" << endl;

		SaveFile.close();
		cout << "Game has been saved!" << endl;
		system("pause");
	}
	else
	{
		i = 0;
		SavesArrayPointer = ArrayCreator2(i);
		int j = 0, k = 0;
		while (LineDivider(k, SavesArrayPointer[j]) != PlaySequenceName)
		{
			j++;
			k = 0;
		}
		SavesArrayPointer[j] = PlaySequenceName + "," + PlayerName + ","
			+ to_string(PlayerHealth) + "," + to_string(PlayerMana) + ","
			+ to_string(PlayerStrength) + "," + to_string(PlayerMagicpower) + ","
			+ to_string(GameProgress) + ",";
	
		fstream SaveFile;
		SaveFile.open("Saves.txt", ios::out);
		if (SaveFile.good() == true)
		{
			for (int k = 0; k <= i - 1; k++)
			{
				SaveFile << SavesArrayPointer[k];
				SaveFile << endl;
			}
		}
		else
			cout << "File access error!" << endl;

		SaveFile.close();
		cout << "Game has been saved!" << endl;
		system("pause");
	}
	
}

void PlaySequence::Promotion()
{
	int AttributeChoice;
	for (int i = 5; i > 0; i--)
	{
		system("cls");
		cout << setw(20) << left << PlayerName << "\t" << setw(25) << endl;
		cout << setw(20) << left << "Attribute points left: " << i << "\t" << setw(25) << endl;
		cout << setw(15) << left << "Health: " << PlayerHealth << "\t" << setw(15) << endl;
		cout << setw(15) << left << "Mana: " << PlayerMana << "\t" << setw(15) << endl;
		cout << setw(15) << left << "Strength: " << PlayerStrength << "\t" << setw(15) << endl;
		cout << setw(15) << left << "MagicPower: " << PlayerMagicpower << endl;
		cout << "-----------------" << endl;
		cout << "Which attribute do You want to upgrade: " << endl;
		cout << "1. +20 Health" << endl;
		cout << "2. +10 Mana" << endl;
		cout << "3. +1 Strength" << endl;
		cout << "4. +1 MagicPower" << endl;
		cout << "Your action(1-4): ";
		cin >> AttributeChoice;

		switch (AttributeChoice)
		{
		case 1:
			PlayerHealth += 20;
			break;
		case 2:
			PlayerMana += 10;
			break;
		case 3:
			PlayerStrength++;
			break;
		case 4:
			PlayerMagicpower++;
			break;
		default:
			cout << "Wrong action, Try again!" << endl;
			i++;
			system("pause");
			break;
		}
	}
}

void PlaySequence::LoadSequence()
{
	int i = 0, j = 0, Choice = 0;

	string* SavesArrayPointer = ArrayCreator2(i);
	
	while (true)
	{
		system("cls");
		PrintArray(SavesArrayPointer, i);

		cout << "Choose game to load: ";
	
		cin >> Choice;
		if ((Choice > i) || (Choice < 1))
		{
			cout << "Wrong choice. Choose 1-" << i << "!" << endl;
			system("pause");
			continue;
		}
		else
			break;
	}
	while (j != Choice - 1)
	{
		j++;
	}
	i = 0;
	PlaySequenceName = LineDivider(i, SavesArrayPointer[j]);
	PlayerName = LineDivider(i, SavesArrayPointer[j]);
	PlayerHealth = stoi(LineDivider(i, SavesArrayPointer[j]));
	PlayerMana = stoi(LineDivider(i, SavesArrayPointer[j]));
	PlayerStrength = stoi(LineDivider(i, SavesArrayPointer[j]));
	PlayerMagicpower = stoi(LineDivider(i, SavesArrayPointer[j]));
	GameProgress = stoi(LineDivider(i, SavesArrayPointer[j]));
	cout << "Game loaded!!" << endl;
	
}

void PlaySequence::Game()
{
	int MiddleChoice;
	int Enemys = EnemysCounter();
	
		for (int i = GameProgress; i <= Enemys; i++)
		{
			if (FightSequence(i+1) == 0)
			{
				system("cls");
				cout << "You lost. Do you want to try again?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cout << "Your choice: ";
				cin >> MiddleChoice;
			}
			else
			{
				GameProgress++;

				if (GameProgress != Enemys)
				{
					Promotion();
					if (GameProgress == 1)
						SaveSequence(0);
					else
						SaveSequence(1);
					system("cls");
					cout << "Do you want to continue?" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					cout << "Your choice: ";
					cin >> MiddleChoice;
					switch (MiddleChoice)
					{
					case 1:
						continue;
					case 2:
						i = 3;
						break;
					}
				}
				else
				{
					WinScreen();
				}
			}
		}
}