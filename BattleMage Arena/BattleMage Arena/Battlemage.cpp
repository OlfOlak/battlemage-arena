#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Battlemage.h"
#include "FileFunctions.h"



using namespace std;

Battlemage::Battlemage()
{
	Name = "Player";
	Health = 100;
	Mana = 100;
	Strength = 10;
	MagicPower = 10;
}

Battlemage::Battlemage(string PlayerName)
{
	Name = PlayerName;
	Health = 100;
	Mana = 100;
	Strength = 10;
	MagicPower = 10;
}

void Battlemage::SwordAttack(Enemy &EnemyObj)
{
	int Damage = Strength - EnemyObj.Armour;
	if (Damage > 0)
	{
		EnemyObj.Health -= Damage;
		cout << Name << " deals " << Damage << " sword damage." << endl;
	}
	else
		cout << EnemyObj.Name << " parrys your attack." << endl;
}

void Battlemage::FireballThrow(Enemy &EnemyObj)
{
	int Damage = MagicPower;
	EnemyObj.Health -= Damage;
	Mana -= (30 - MagicPower);
	cout << Name << " deals " << Damage << " fireball damage." << endl;
}

void Battlemage::SwordParry(int &SwordParry_ArmourCounter, Enemy &EnemyObj)
{
	int Damage = EnemyObj.Attack - Strength;
	if (Damage > 0)
	{
		Health -= Damage;
		cout << EnemyObj.Name << " deals " << Damage << " damage." << endl;
		
	}
	else
	{
		cout << Name << " parrys enemy's attack." << endl;
	}
}

void Battlemage::MagicResist(int &MagicResist_AttackCounter, Enemy &EnemyObj)
{
	Mana -= EnemyObj.Attack;
	cout << "Magic shield resisted " << EnemyObj.Attack << " damage." << endl;
}


Battlemage::~Battlemage()
{
}
