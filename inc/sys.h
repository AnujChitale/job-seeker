// System dependant functions mentioned here

#ifndef __SYS_H_INCLUDED__
#define __SYS_H_INCLUDED__

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;

void clearscr(void)
{
	system("clear");
}

void nokeybuff(void)
{
    struct termios t;	
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

#endif /* __SYS_H_INCLUDED__ */
