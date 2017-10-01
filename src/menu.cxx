//Functionality of the menu class

#include <iostream>
#include <stdio.h>

#include "../inc/commands.h"
#include "../inc/menu.h"
#include "../inc/style.h"
#include "../inc/sys.h"
#include "../inc/keys.h"

using namespace std;

//////////////////////////////Class functions//////////////////////////////

CMenu::CMenu(void)
{
	pos = LIST_EMPTY;
	list_len = DEF_MENU_LEN;
	arr_list = new CMenuItem[DEF_MENU_LEN];
}
CMenu::CMenu(int len)
{
	pos = LIST_EMPTY;
	list_len = len;
	arr_list = new CMenuItem[len];		
}

CMenu::~CMenu(void)
{
	delete arr_list;
}

int CMenu::AddItem(char* text, void (*handler)(void))
{
	++pos;
	if (pos < list_len)
	{
		arr_list[pos].id = pos;

		//fputs(text,stdout);
		strncpy(arr_list[pos].txt, text, sizeof(arr_list[pos].txt));

		if (handler) {
			arr_list[pos].handle = handler;
		}
	}
	else {
		cout <<"ERROR: list items exceed max allowed" <<endl;
	}
}

void CMenu::ShowItem(int n)
{
	fputs(arr_list[n].txt, stdout);
	cout <<endl;
}

//////////////////////////////Get-Set functions//////////////////////////////
void CMenu::SetCurrItem(int item)
{
	curr_item = item;
}

int CMenu::GetCurrItem(void)
{
	return curr_item;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


CCmdMenu::CCmdMenu(void) : CMenu()	//The default constructor will store nothing, resulting in a blank display.
{	
	;
}

CCmdMenu::CCmdMenu(int len, int mask) : CMenu(len)
{

	;
	CreatCmdArr(mask);
}

CCmdMenu::CCmdMenu(int len, CmdBits_e arr[]) : CMenu(len)
{
	int i;
	CreatCmdArr(arr);
	
}

CCmdMenu::~CCmdMenu(void)		
{
	;
}

//TODO
void CCmdMenu::CreatCmdArr(int mask)
{
	int i;

	for (i=1; i<(MAX_CMDS-1); i++)
	{
		if (mask & (BIT << i))
			{
				;
			}
		else {
			;			
		}
	}
}
void CCmdMenu::CreatCmdArr(CmdBits_e cmd_arr[])
{
	int i;
	char tmp_txt[7];
	CmdBits_e tmp_cmd;

	SetCurrCmd(0);

	for (i=0; cmd_arr[i] && i< list_len; i++)
	{		
		tmp_cmd = cmd_arr[i];
		strncpy(tmp_txt, ALLWD_CMDS[tmp_cmd], CMD_TXT_LEN);		
		AddItem(tmp_txt, NULL);
	}
}

//TODO
void CCmdMenu::ShowCmdMenu(void)
{
	int i;
	clearscr();
	offset_row(15);

	for (i=0; i <= pos; i++)
	{
		offset_col(25);
		if (arr_list[i].id == GetCurrCmd()) {
			fputs(">> ", stdout);
		}
		cout <<arr_list[i].txt <<endl;
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