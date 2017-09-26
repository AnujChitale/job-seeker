#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./inc/interface.h"
#include "./inc/commands.h"

using namespace std;



int fun_cat(char *buf)
{
	char cmd[150] = {"cat "};
	strcat(cmd,buf);
	system(cmd);
	return 0;
}

int main(void)
{
	// char pat[100]={"/home/anuj/Anuj/jobseek"};
	// strcat(pat, "/laptop_config.txt");
	// fun_cat(pat);

	FILE* show = NULL;
	char* buff[1024] = {"abc"};
	char* buffer= {"NOT_hello"};
	int retval = 0, i;
	CIface Inter1;
	
	system("clear");
	//Read from this file
	show = fopen("./DOCS/laptop_config.txt", "r");
	retval = fread(buff, 1, 1024, show);
	printf("BUFFER CONTENTS-\r\n%s\r\n", buff);
	//cout << buff <<endl;
	fclose(show);

	Inter1.SetHeader("BOss level 50\r\n");
	Inter1.ViewHeader();

	system("clear");
	for (i=0; i< 35; i++)
	{
		fputs("\r\n", stdout);
	}

	for (i=1; cmd_arr[i][0] !='\0'; i++)
	{
		fputs(" || ", stdout);
		fputs(cmd_arr[i], stdout);
	}
	fputs("\r\n", stdout);


	return 0;
}