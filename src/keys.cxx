//Functionality related to keyboard keys

#include <iostream>
#include <stdio.h>

#include "../inc/commands.h"
#include "../inc/sys.h"
#include "../inc/keys.h"

using namespace std;


KeyMap_e CKeyIn::ParseKey(void)
{
	int key;
	KeyMap_e retval = KEY_ERR;

	key = fgetc(stdin);
	putchar(8);
	putchar(32);
	putchar(8);

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