#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <conio.h>

//Pfeiltaste abfragen
int getKey()
{
   int result=getch();
   if(result==0)
      result=256+getch();
   else if(result==224)
      result=512+getch();
   return result;
}

void gotoxy(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput,scrn);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
	//cursorInfo.dwSize = 50; // scheinbar nicht notwendig
}
