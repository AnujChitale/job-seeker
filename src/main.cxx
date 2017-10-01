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
#include "../inc/keys.h"


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

	//MainScreen_s.DispHeader();
	//TESTBLOCK
	
	
	//TESTBLOCK

	//TESTBLOCK
	{
		int mask = 0;
		int j;
		bool test_bool = false;

		CmdBits_e tmp_arr[] = {ESCP,HELP,CMDS,QUIT, NO_CMD};
		CCmdMenu testmenu(4, tmp_arr);
		
		// CCmdMenu testmenu(2);

		while (true)
		{			
			KeyMap_e tst_key;
			cout <<"Welcome to the test version of the app" <<endl;
			tst_key = CKeyIn::ParseKey();
			if (tst_key == ESC_KEY) {				
				testmenu.ShowCmdMenu();
			}

			while (true)
			{				
				KeyMap_e new_key;
				bool exit = false;

				new_key = CKeyIn::ParseKey();
				if (new_key == ESC_KEY)
					return 0;		
			}
		}	
	}
		
	//TESTBLOCK
	
	
	//TESTBLOCK
	clearscr();
	return 0;
}