#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/commands.h"
#include "../inc/sizes.h"
#include "../inc/keys.h"

#define DEF_MENU_LEN 2
#define LIST_EMPTY -1
#define MAX_ITEM_TXT 20



//////////////////////////////Class definitions//////////////////////////////
/*CMenuItem: The linked list object for populating the menu.
*
*/
class CMenuItem
{
public:
	int id;					//The item number within the menu.
	char txt[MAX_ITEM_TXT];				//Text to display.
	void (*handle)(void);	//The callbackfunction associated with this item.
};


/*CMenu: Responsible for menu display functionality and detecting defined key presses.
*
*/
class CMenu
{
public:
	CMenu(void);		//Use the default number of menu items.
	CMenu(int len);		//Declare the number of menu items to be used.
	~CMenu(void);

	//TODO
	int AddItem(char* text, void (*handler)(void));		//Add a new item to the menu

	void ShowItem(int n);		//Displays the menu item passed to it.

	//////////////////////////////Get-Set functions//////////////////////////////
	//void SetCmdArr(CmdBits_e arr);		//Store the allowed commands array.
	//CmdBits_e GetCmdArr();

	void SetCurrItem(int item);		//Set the currently selected item.
	int GetCurrItem(void);			//Return the currently selected item.	


//TODO Do we need private members for this base class?
protected:
	int curr_item;		//The integer corresponding to the currently selected item.
	CMenuItem* arr_list;	//The poiner to dynamic array items.
	int list_len;		//number of menu items
	int pos;		//Keep track of how many list items are filled.
	
};

/*CCmdMenu: Menu for the input commands
*
*/
class CCmdMenu : public CMenu
{
public:
	CCmdMenu(void);
	CCmdMenu(int len, int mask);				//The mask of allowed items.
	CCmdMenu(int len, CmdBits_e arr[]);		//The array list must be ended with the enum value 'NO_CMD' for recognising end of array.
	~CCmdMenu(void);

	

	void CreatCmdArr(int mask);				//Populate the command array from provide command mask.
	void CreatCmdArr(CmdBits_e cmd_arr[]);	//Populate the command array from the CmdBits_e array.
	void ShowCmdMenu(void);					//Display the command

	//////////////////////////////Get-Set functions//////////////////////////////
	void SetCurrCmd(int cmd);	//Set the currently selected command.
	int GetCurrCmd(void);		//Return the currently selecte command.

private:
	
	int curr_cmd;				//Stores the currently selected item from the menu.


};



#endif /* __MENU_H_INCLUDED__ */