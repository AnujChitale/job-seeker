#ifndef __KEYS_H_INCLUDED__
#define __KEYS_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>



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


//////////////////////////////class definitions//////////////////////////////
class CKeyIn
{
public:
	static KeyMap_e ParseKey(void);		//Take input key and return the mapped value. Return -1 on failure i.e undefined in keymap.
};


#endif /* __KEYS_H_INCLUDED__ */