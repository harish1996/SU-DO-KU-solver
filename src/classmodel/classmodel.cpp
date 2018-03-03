#include <iostream>
#include <stdint.h>
#include <string.h>

class cell
{
	row* row_n;
	column* column_n;
	box* box_n;
	uint16_t possibles;
	uint8_t value;
}

class row
{
	uint16_t possibles;
	cell* cells[9];

	uint8_t conflict();
}

class column
{
	uint16_t possibles;
	cell* cells[9];
}

class box
{
	uint16_t possibles;
	cell* cells[9];
}

class table
{
	row rows[9];
	column columns[9];
	box boxes[9];
	cell cells[81];

	table( char* sudoku );
	uint8_t row_conflict( uint8_t num );
	uint8_t column_conflict( uint8_t num );
	uint8_t box_conflict( uint8_t num );
}

table::table( char* sudoku )
{
	uint8_t row=0,column=0;
	uint8_t count=0;
	uint8_t rc,cc,bc;
	if(strlen(sudoku) != 81 ){
		cout<< " Not a proper input ";
	}
	for( count=0 ; count<81 ; count++ ){
		cells[count]=*(sudoku+count);
		rows[row].cells[column]=&cells[count];
		columns[column].cells[row]=&cells[count];
		boxes[ (row/3)*3 + (column/3) ].cells[ (row%3)*3 + (column%3) ]=&cells[count];
		cells[count].row_n=&rows[row];
		cells[count].column_n=&columns[column];
		cells[count].box_n=&boxes[ (row/3)*3 + (column/3) ];
		row += (++column)/9;
		column /= 9;
	}
	for( count=0; count<9 ; count++ ){
		rc=row_conflict( count );
		cc=column_conflict( count );
		bc=box_conflict( count );
		if(ac+bc+cc == 0 )
		{
			cout << " No Conflicts found ! in " << count;
		}
		else{
			cout<< "Conflict in" << (rc != 0)?"row,":"" << (cc != 0)?"column,":"" << (bc != 0)?"box ":"" << count;
		}
	}
}

uint8_t table::row_conflict( uint8_t num )
{
	return rows[num].conflict();
}

uint8_t row::conflict()
{
	uint8_t counts;
	uint16_t possibles=0;
	unsigned char temp;
	for ( counts=0 ; counts<9 ; counts++ ){
		temp=cells[counts]->value;
		if( temp != '0' ){
			if( possibles & ( 1 << ( temp - '0' ) ) != 0 ){
				return count;
			}
			else{
				possibles |= ( 1 << temp );
			}
		}
	}
}
	

