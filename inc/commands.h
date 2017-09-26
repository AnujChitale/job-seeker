//Just mention the commands here?

#ifndef __COMMANDS_H_INCLUDED__
#define __COMMANDS_H_INCLUDED__

#include <iostream>
#include <stdio.h>

//////////////////////////////Size macros//////////////////////////////
#ifndef MAX_CMDS
#define MAX_CMDS 15
#endif

using namespace std;

/*Enumtype to toggle the bitmask for bottom- avail bar 
and also to track the state of program.
*/
typedef enum
{
	NO_CMD = 0,
	ESCP,
	HELP,
	LIST,
	ADDE,
	DELE,
	EDIT,
	SAVE,
	NEXT,
	PREV,
	CMDS,
	QUIT
}
CmdBits_e;

//Commands array to compare with the input.
const char cmd_arr[MAX_CMDS][7] = {"NO_CMD", "ESCP", "HELP", "LIST", "ADDE", "DELE", "EDIT", "SAVE", "NEXT", "PREV", "CMDS", "QUIT", "\0"};


class CCmds
{
public:
	CCmds(void);
	~CCmds(void);


}; 


#endif /* __COMMANDS_H_INCLUDED__ */