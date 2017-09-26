#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include <iostream>
#include <stdio.h>

#include "../inc/commands.h"
#include "../inc/sizes.h"


//////////////////////////////enum definitions//////////////////////////////
/*KeyMap_e: Assign action names to various keys.
* TODO: currently it's a mix of chars, hex and ints because \
* the method of getting keymaps form keyboard interrupts hasn't been fixed yet.
*/
typedef enum
{
	KEY_ERR = -1,
	UP_KEY = 'w',
	DOWN_KEY = 'z',
	LEFT_KEY = 'a',
	RIGHT_KEY = 's',
	ESC_KEY = 27,
	OK_KEY = 0x0d,
}KeyMap_e;




//////////////////////////////Class definitions//////////////////////////////
/*CMenu: Responsible for menu display functionality and detecting defined key presses.
*
*/
class CMenu
{
public:
	CMenu(void);
	~CMenu(void);

	void ShowItem(char* item);		//Displays the menu item passed to it.
	KeyMap_e ParseKey(void);		//Take input key and return the mapped value. Return -1 on failure i.e undefined in keymap.



	//////////////////////////////Get-Set functions//////////////////////////////
	//void SetCmdArr(CmdBits_e arr);		//Store the allowed commands array.
	//CmdBits_e GetCmdArr();

	void SetCurrSel(int item);		//Set the currently selected item.
	int GetCurrSel(void);			//Return the currently selected item.

	void SetCurrKey(KeyMap_e key);	//Latest pressed key.
	KeyMap_e GetCurrKey(void);		//Return the latest key hit.
	


//TODO Do we need private members for this base class?
protected:
	int curr_item;							//The integer corresponding to the item number.
	KeyMap_e curr_key;					//Store the currently hit key
// 	CmdBits_e allwd_cmd[MAX_CMDS];		//Will store only those enum values corresponding to the allowed command. 
// 	CmdBits_e curr_sel;					//Stores the currently selected item from the menu.
};

/*CCmdMenu: Menu for the input commands
*
*/
class CCmdMenu : CMenu
{
public:
	CCmdMenu(void);
	CCmdMenu(int mask);				//The mask of allowed items.
	CCmdMenu(CmdBits_e arr[]);		//The array list must be ended with the enum value 'NO_CMD' for recognising end of array.
	~CCmdMenu(void);

	void CreatCmdArr(int mask);		//Create the command enum array from provide command mask.
	void ShowCmdMenu(void);			//Display the command

	//////////////////////////////Get-Set functions//////////////////////////////
	void SetCurrCmd(int cmd);	//Set the currently selected command.
	int GetCurrCmd(void);		//Return the currently selecte command.

	int allwd_cmd[MAX_CMDS];	//Will store only those enum values corresponding to the allowed command. 

private:
	
	int curr_cmd;				//Stores the currently selected item from the menu.


};



#endif /* __MENU_H_INCLUDED__ */