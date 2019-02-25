// BattleMage Arena.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Battlemage.h"
#include "Enemy.h"
#include "Interface.h"
#include "FileFunctions.h"
#include "PlaySequence.h"


using namespace std;

int main()
{

	StartScreen();
	PlaySequence GameObj;
	while (GameObj.MainMenu() == 1)
	{
		;
	}
	system("pause");
    return 0;
}

