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

		CmdBits_e tmp_arr[] = {ESCP,HELP,LIST,CMDS,QUIT,NO_CMD};

		mask = Mainface_i.CreatMask(tmp_arr);
		CBitflag TstFlag_f(mask,16);		

		for (j=0; cmd_arr[j][0]; j++)
		{
			TstFlag_f.SetPlace(j);			
			test_bool = TstFlag_f.ChkFlag();	
			
			if (test_bool == true)
			{
				fputs(" || ", stdout);
				fputs(cmd_arr[j], stdout);
			}			
		}		
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
	{
		CmdBits_e tmp_arr[] = {ESCP,HELP,CMDS,QUIT, NO_CMD};
		CCmdMenu testmenu(tmp_arr);
		testmenu.SetCurrCmd(HELP);
		// CCmdMenu testmenu(2);
		testmenu.ShowCmdMenu();
	}
	//TESTBLOCK

	return 0;
}