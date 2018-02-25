#ifndef _PRETTYPRINT_H_
#define _PRETTYPRINT_H_

#include <iostream>
#include <string.h>

/* print_table - Pretty Prints the input character sudoku table buffer 
 * @table => Character buffer to print ( must be 81 characters in length exactly )
 *
 * Returns :
 * 0 on success
 * -1 on failure if string length != 81
 */
int print_table ( char* table );

#endif
