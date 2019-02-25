#pragma once

using namespace std;

class Enemy
{
public:
	string Name;
	int Health;
	int Armour;
	int Attack;
	int ArmourIncrement;
	int AttackIncrement;

	// Constructors and dustructor.
	Enemy();
	Enemy(string OutName);
	Enemy(string outName, int OutHealth);
	Enemy(string OutName, int OutHealth, int OutArmour);
	Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack);
	Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack, int OutArmourIncrement);
	Enemy(string OutName, int OutHealth, int OutArmour, int OutAttack, int OutArmourIncrement, int OutAttackIncrement);
	~Enemy();

	// Methods.
	void ReverseArmourIncrements(int &enemyClass_ArmourCounter);
	void ReverseAttackIncrements(int &enemyClass_AttackCounter);
	void IncrementArmour();
	void IncrementAttack();
	void LoadEnemy(int EnemyCount);

	

	

};




