#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/interface.h"
#include "../inc/sys.h"
#include "../inc/flags.h"
#include "../inc/screen.h"
#include "../inc/sizes.h"
#include "../inc/menu.h"
#include "../inc/style.h"


using namespace std;

CIface Mainface_i;
CScreen MainScreen_s;

int main(void)
{
	char c = 'a';
	int i;
	bool quit = false;

	nokeybuff();
	clearscr();

	MainScreen_s.DispHeader();

	//TESTBLOCK
	{
		int mask = 0;
		int j;
		bool test_bool = false;


		offset_row(20);


		CmdBits_e tmp_arr[] = {ESCP,HELP,CMDS,QUIT, NO_CMD};
		CCmdMenu testmenu(tmp_arr);
		testmenu.SetCurrCmd(HELP);
		// CCmdMenu testmenu(2);
		testmenu.ShowCmdMenu();

	}
		

	//TESTBLOCK

	while(true)
	{
		c = cin.get();
		if (iscntrl(c) && 27==c)
		{
			clearscr();
			fputs(header_arr[ESC_SCR], stdout);
			cout <<endl;
			//cout <<"Quit?(y/n)\r\n";
			while (c != 'y')
			{
			c = cin.get();
			if (c== 'y' || c== 'Y') {
				quit = true;
				break;
				}	
			}

			if (quit == true) {
			clearscr();
			break;
			}		

		}
		else {
			putchar(8);
			putchar(32);
			putchar(8);
			//fputc(8,stdout);
			//fputc(8,stdout);
		}
	}

	//TESTBLOCK
	while (true)
	{
		CMenu tst_menu;
		KeyMap_e tst_key;
		tst_key = tst_menu.ParseKey();

		switch (tst_key)
		{
			case UP_KEY:
			cout <<"UP_KEY or w pressed" <<endl;
			break;

			case DOWN_KEY:
			cout <<"DOWN_KEY or z pressed" <<endl;
			break;

			case LEFT_KEY:
			cout <<"LEFT_KEY or a pressed" <<endl;
			break;

			case RIGHT_KEY:
			cout <<"RIGHT_KEY or s pressed" <<endl;
			break;

			default:
			break;
		}

		if (tst_key == ESC_KEY)
			break;
		
	}
	
	//TESTBLOCK

	return 0;
}