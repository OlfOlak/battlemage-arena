#pragma once
class GameSave
{
	string SaveName;
	string PlayerName;
	int Health;
	int Mana;
	int Strength;
	int MagicPower;

public:
	GameSave(string gameSave_SaveName, string gameSave_PlayerName, int gameSave_Health, int gameSave_Mana, int gameSave_Strength, int gameSave_MagicPower);
	~GameSave();
};

