#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

unsigned long int filesize( FILE *fp )
{
	int check;
	unsigned long int filesize;
	check = fseek ( fp , 0 , SEEK_END );
	filesize = ftell ( fp );
	rewind( fp );
	return filesize;
}

char* readfile( FILE *fp )
{
	unsigned long int size;
	if( ( size = filesize( fp ) ) < 81 ){
		cout << " Given file does not contain enough table data. Filesize less than 81\n ";
		return NULL;
	}
	else if( size > 81){
		cout << " Truncating file and taking first 81 characters of this file \n";
	}
	char *mem=( char * )malloc( 81*sizeof(char));
	if ( mem == NULL ){
		cout << strerror(errno);
		return NULL;
	}
	if ( fread ( mem , 9 , 9 , fp ) == 0 ){
		cout << strerror(errno);
		free( mem );
		return NULL;
	}
	return mem;
}
	
char* get_sudoku_table( FILE *fp )
{
	int counter=0;
	char *table_data = readfile( fp );
	if( table_data == NULL ){
		cout<< " Reading file was unsuccessful \n";
		return NULL;
	}
	for ( counter = 0 ; counter < 81 ; counter ++ ){
		if( *(table_data + counter) < '0' || *(table_data + counter) > '9' ){
			cout<< "Invalid Data in the table \n";
			free(table_data);
			return NULL;
		}
	}
	return table_data;
}
	

int main( int argc , char* argv[] )
{
	FILE *fp;
	char *table;
	char temp;
	fp = (FILE*) fopen ( argv[1] , "r" );
	if ( fp == NULL ){
		cout << strerror(errno) << "\n";
		goto out1;
	}
	if( ( table=get_sudoku_table( fp ) ) != NULL ){
		for( int i=0 ; i<9 ; i++ ){
			for( int j=0; j<9 ; j++){
				temp = *( table + (i*9) + j);
				if ( temp == '0' ){
					temp = ' ';
				}
				cout << temp << " ";
			}
			cout << "\n";
		}
		free(table);
	}
	fclose( fp );
out1:
	return 0;
}
	
