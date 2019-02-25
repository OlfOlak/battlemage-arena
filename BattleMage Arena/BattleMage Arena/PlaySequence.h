#pragma once
class PlaySequence
{
public:
	string PlaySequenceName;
	string PlayerName;
	int PlayerHealth;
	int PlayerMana;
	int PlayerStrength;
	int PlayerMagicpower;
	int GameProgress;

	PlaySequence();
	~PlaySequence();
	
	bool MainMenu();
	void Game();
	int FightSequence(int FightSequenceCounter);
	void SaveSequence(bool Mode);
	void LoadSequence();
	void Promotion();
};

