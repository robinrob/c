/* base_change.h
 *
 * Header file for the base_change project.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BASE	36		 //max value for number system base using characters
							 //0-9 and A-Z
#define MAX_NUM		~(1 << (sizeof(int) * 8 - 1))  //maximum int value
#define NULL_INT	-1		 //used as a null value for ints
#define MAX_STRING   1000000 //max length of number strings

typedef char * num_string;

#include "calc.h"
#include "error.h"
#include "get.h"
#include "print.h"
