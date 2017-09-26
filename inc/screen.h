#ifndef __SCREEN_H_INCLUDED__
#define __SCREEN_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../inc/interface.h"

using namespace std;


/* ScrType: This will effectively control what parameters to pass to the interface.
*
*/
typedef enum
{
	MAIN_SCR = 0,
	ESC_SCR,
	LIST_SCR,
	EDIT_SCR,
	HELP_SCR,
	MAX_SCRS	
}ScrType_e;

const char header_arr[MAX_SCRS][100] =
{
	/*MAIN_SCR*/
	"		Welcome to the job seeker app\r\n \
		version 1.0\r\n \
		created by- Anuj C",

	/*ESC_SCR*/
	"		Quit already?\r\n \
		(y/n)"
};



/*CScreen: The class that contains all the screen info
*
*/
class CScreen : public CIface 
{
public:
	CScreen();
	CScreen(ScrType_e type);
	~CScreen();

	//void DispHeader(void);



private:
	ScrType_e curr_scr;		//Know which kind of screen it is
	int footer_mask;		//
		

};




#endif /* __INTERFACE_H_INCLUDED__ */