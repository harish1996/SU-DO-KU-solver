
#include "prettyprint.h"

using namespace std ;

int print_table( char* table )
{
	char temp;
	if( strlen(table) != 81 ){
		cout<< "Less number of numbers in the given input\n";
		return -1;
	}
	cout<<"\n";
	for( int i=0; i<3 ; i++ ){
		cout<<"\n";
		for( int j=0; j<3 ; j++){
			cout<<" ";
			for( int k=0; k<3 ; k++){
				cout<<" ";
				for( int l=0; l<3 ; l++){
					temp = *( (char*)table + 27*i + 9*j + 3*k + l );
					if( temp != '0' )
						cout<< *( (char*)table + 27*i + 9*j + 3*k + l );
					else
						cout<<" ";
					cout<<" ";
				}
				cout<<" ";
			}
			cout<<" \n";
		}
		cout<<"\n";
	}
	cout<<"\n";
	return 0;
}




