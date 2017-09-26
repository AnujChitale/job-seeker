//Functionality of the menu class

#include <iostream>
#include <stdio.h>

#include "../inc/commands.h"
#include "../inc/menu.h"

using namespace std;

//////////////////////////////Class functions//////////////////////////////

CMenu::CMenu(void)
{
	;
}

CMenu::~CMenu(void)
{
	;
}

void CMenu::ShowItem(char* item)
{
	fputs(item, stdout);
	cout <<endl;
}

KeyMap_e CMenu::ParseKey(void)
{
	int key;
	KeyMap_e retval = KEY_ERR;

	key = fgetc(stdin);

	switch (key)
	{
		case KEY_ERR:
		retval = KEY_ERR;
		break;

		case UP_KEY:
		retval = UP_KEY;
		break;

		case DOWN_KEY:
		retval = DOWN_KEY;
		break;
		
		case LEFT_KEY:
		retval = LEFT_KEY;
		break;
		
		case RIGHT_KEY:
		retval = RIGHT_KEY;
		break;
		
		case ESC_KEY:
		retval = ESC_KEY;
		break;
		
		case OK_KEY:
		retval = OK_KEY;
		break;
		
		default:
		retval = KEY_ERR;
		break;
	}

	return retval;
}

//////////////////////////////Get-Set functions//////////////////////////////
void CMenu::SetCurrSel(int item)
{
	curr_item = item;
}

int CMenu::GetCurrSel(void)
{
	return curr_item;
}

void CMenu::SetCurrKey(KeyMap_e key)
{
	curr_key = key;
}

KeyMap_e CMenu::GetCurrKey(void)
{
	return curr_key;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


CCmdMenu::CCmdMenu(void)	//The default constructor will store nothing, resulting in a blank display.
{
	SetCurrCmd( 1);
	CreatCmdArr(0);
}

CCmdMenu::CCmdMenu(int mask)
{
	SetCurrCmd(1);
	CreatCmdArr(mask);
}

CCmdMenu::CCmdMenu(CmdBits_e arr[])
{
	int i;
	SetCurrCmd(1);

	for (i=0; (arr[i] != 0 && i< (MAX_CMDS-1)); i++)
	{
		allwd_cmd[i] = (int)arr[i];		
	}
	allwd_cmd[i] = 0;
}

CCmdMenu::~CCmdMenu(void)		
{
	;
}

void CCmdMenu::CreatCmdArr(int mask)
{
	int i;

	for (i=1; i<(MAX_CMDS-1); i++)
	{
		if (mask & (BIT << i))
			allwd_cmd[i] = i;
		else
			allwd_cmd[i] = 0;
	}
}

//TODO
void CCmdMenu::ShowCmdMenu(void)
{
	int i, tmp_cmd =0;


	for (i=0; allwd_cmd[i] && i<(MAX_CMDS-1); i++)
	{
		
		if (allwd_cmd[i] == GetCurrCmd() && 0 != GetCurrCmd())
		{
			fputs(">>  ", stdout);
		}

		tmp_cmd = allwd_cmd[i];
		if ( tmp_cmd!= 0)
		{
			fputs(cmd_arr[tmp_cmd], stdout);
			cout <<endl;
		}
	}
}

//////////////////////////////Get-Set functions//////////////////////////////
void CCmdMenu::SetCurrCmd(int cmd)
{
	curr_cmd = cmd;
}

int CCmdMenu::GetCurrCmd(void)
{
	return curr_cmd;
}