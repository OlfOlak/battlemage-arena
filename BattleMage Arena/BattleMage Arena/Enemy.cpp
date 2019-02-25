#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Enemy.h"
#include "FileFunctions.h"



Enemy::Enemy()
{
	Name = "Enemy1";
	Health = 10;
	Armour = 1;
	Attack = 1;
	ArmourIncrement = 1;
	AttackIncrement = 1;
}

Enemy::Enemy(string OutName)
{
	Name = OutName;
	Health = 10;
	Armour = 1;
	Attack = 1;
	ArmourIncrement = 1;
	AttackIncrement = 1;
}

Enemy::Enemy(string OutName, int OutHealth)
{
	Name = OutName;
	Health = OutHealth;
	ArmourIncrement = 1;
	AttackIncrement = 1;
}

Enemy::Enemy(string OutName, int OutHealth, int OutArmour)
{
	Name = OutName;
	Health = OutHealth;
	Armour = OutArmour;
	ArmourIncrement = 1;
	AttackIncrement = 1;
}

Enemy::Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack)
{
	Name = OutName;
	Health = OutHealth;
	Armour = OutArmour;
	Attack = OutAttack;
	ArmourIncrement = 1;
	AttackIncrement = 1;
}
Enemy::Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack, int OutArmourIncrement)
{
	Name = OutName;
	Health = OutHealth;
	Armour = OutArmour;
	Attack = OutAttack;
	ArmourIncrement = OutArmourIncrement;
	AttackIncrement = 1;
}
Enemy::Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack, int OutArmourIncrement, int OutAttackIncrement)
{
	Name = "Enemy1";
	Health = OutHealth;
	Armour = OutArmour;
	Attack = OutAttack;
	ArmourIncrement = OutArmourIncrement;
	AttackIncrement = OutAttackIncrement;
}

Enemy::~Enemy()
{
}

void Enemy::ReverseArmourIncrements(int &enemyClass_ArmourCounter)
{
	Armour -= enemyClass_ArmourCounter*ArmourIncrement;
	enemyClass_ArmourCounter = 0;
}
void Enemy::ReverseAttackIncrements(int &enemyClass_AttackCounter)
{
	Attack -= enemyClass_AttackCounter*AttackIncrement;
	enemyClass_AttackCounter = 0;
}
void Enemy::IncrementArmour()
{
	Armour += ArmourIncrement;
}
void Enemy::IncrementAttack()
{
	Attack += AttackIncrement;
}
void Enemy::LoadEnemy(int EnemyCount)
{
	fstream File;
	string Line, temp;
	int i = 1;

	File.open("Enemys.txt", ios::in);
	if (File.good() == true)
	{
		while (i != EnemyCount)
		{
			getline(File, temp);
			i++;
		}
		getline(File, Line);
	}
	else
	{
		cout << "Problem with file access!!" << endl;
	}
	File.close();
	i = 0;

	// Entering enemyobject's attributes.
	Name = LineDivider(i, Line);
	Health = stoi(LineDivider(i, Line));
	Armour = stoi(LineDivider(i, Line));
	Attack = stoi(LineDivider(i, Line));
	ArmourIncrement = stoi(LineDivider(i, Line));
	AttackIncrement = stoi(LineDivider(i, Line));
}