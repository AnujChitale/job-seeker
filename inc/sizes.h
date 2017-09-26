//Mention the size constants and varied flag-types here.

#ifndef __SIZES_H_INCLUDED__
#define __SIZES_H_INCLUDED__

#include <iostream>
#include <stdio.h>


//////////////////////////////Operational macros//////////////////////////////
#define BIT	1	
#define NOBIT !BIT	


typedef unsigned short int Bitmask_short;	//Use this typedef to classify short ints used for bit flags.
typedef int Bitmask_int;	//Use this typedef to classify ints used for bit flags.


#endif /* __SIZES_H_INCLUDED__ */