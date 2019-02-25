#pragma once
#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

string LineDivider(int &CharCounter, string InputLine);
bool SaveNameCheck(string SaveName);
string* ArrayCreator(string ExtraLine, int &Counter);
string* ArrayCreator2(int &Counter);
void PrintArray(string* ArrayPointer, int ArrayCounter);
int EnemysCounter();

#endif // !FILEFUNCTIONS_H

