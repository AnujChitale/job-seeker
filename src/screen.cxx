//Functionality of the screen

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/screen.h"


using namespace std;

CScreen::CScreen(void)
{
	;
}

CScreen::CScreen(ScrType_e type)
{
	curr_scr = type;
}

CScreen::~CScreen()
{
	;
} 


// void CScreen::DispHeader(void)
// {
// 	int i;
// 	fputs(header_arr[MAIN_SCR], stdout);
// 	cout <<endl;
// 	for (i=0; i< 30; i++)
// 	{
// 		fputs("\r\n", stdout);
// 	}
// }
















