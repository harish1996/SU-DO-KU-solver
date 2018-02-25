#include <iostream>
#include <stdint.h>

class cell
{
	uint16_t possibles;
	uint8_t row;
	uint8_t column;
	uint8_t box;
}

class row
{
	uint16_t possibles;
	cell* cells[9];
	uint8_t number;
}

class column
{
	uint16_t possibles;
	cell* cells[9];
	uint8_t number;
}

class box
{
	uint16_t possibles;
	cell* cells[9];
	uint8_t number;
}
