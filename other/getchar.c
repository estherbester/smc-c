#include <stdio.h>

#define TAB '\t'
#define ALTTAB 1
#define TABSTOP 5
#define SPACE ' ' 

void processtabs( int tabstop, int character);

int main (void){

	int iochar;

	while ((iochar = getchar()) != EOF)
	{
	
		if (( iochar == TAB) || (iochar == ALTTAB))
		{
		    processtabs( TABSTOP, SPACE);

		}
		else
		{
			putchar (iochar);
		
		}
	
	}


	return 0;
}

void processtabs ( int tabstop, int character) {

	int colcount = 0;
	while (colcount++ < tabstop)
		putchar (character);

}
