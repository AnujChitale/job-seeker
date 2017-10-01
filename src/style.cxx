//Functions for the styling 
//TODO- shouldn't these be included within a class?

#include <iostream>
#include <stdio.h>

#include "../inc/style.h"

using namespace std;


void offset_col(int col)
{
	int i;

	for (i= col;i> 0;i--)
	{
		fputs(" ", stdout);
	}
}

void offset_row(int row)
{
	int i;

	for (i= row;i> 0;i--)
	{
		fputs("\n", stdout);
		//cout <<"\n" <<endl;
	}
}