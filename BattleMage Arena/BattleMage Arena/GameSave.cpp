#include "stdafx.h"
#include "GameSave.h"
#include "Battlemage.h"



GameSave::GameSave(string gameSave_SaveName, string gameSave_PlayerName, int gameSave_Health, int gameSave_Mana, int gameSave_Strength, int gameSave_MagicPower)
{
	SaveName = gameSave_SaveName;
	PlayerName = gameSave_PlayerName;
	Health = gameSave_Health;
	Mana = gameSave_Mana;
	Strength = gameSave_Strength;
	MagicPower = gameSave_MagicPower;
}


GameSave::~GameSave()
{
}
