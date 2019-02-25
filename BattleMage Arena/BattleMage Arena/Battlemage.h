#include <iostream>
#include "Enemy.h"
#include "PlaySequence.h"
#pragma once

using namespace std;

class Battlemage
{
public:
	string Name;
	int Health;
	int Mana;
	int Strength;
	int MagicPower;
	
	// Constructors.
	Battlemage();
	Battlemage(string PlayerName);

	// Fight methods.
	void Battlemage::SwordAttack(Enemy &EnemyObj);
	void Battlemage::FireballThrow(Enemy &EnemyObj);
	void Battlemage::SwordParry(int &SwordParry_OriginalEnemyArmour, Enemy &EnemyObj);
	void Battlemage::MagicResist(int &MagicResist_OriginalEnemyAttack, Enemy &EnemyObj);

	// Logistics.
	

	// Destructor.
	~Battlemage();
};

