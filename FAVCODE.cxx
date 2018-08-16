
		/********************************#
	   #   Inca's Matrix Demo				  #
	  #	Licensed under MIT license  #
	 #	 Eduardo de Lima Gouvea	  #
	#********************************/

/**
This code is mine favorite one:
It's because was the first time a question made me
think a lot to achieve an adaquated answer
*/
#include <iostream>
#include <string>

#define TOTAL ( counter <= total )

using namespace std;

int lines = 0, cols = 0;

void incaMatrix( int, int );

int main ()
{
	/**variables*/
	int baby = 0, side = 0;
	/**messages*/
	string  wellcome	= "\tHello! i'm an inca's matrix program",
				explanation = "\tI can build shapes based on inca\'s matrix",
				size			  = "select side size and zero",
				valid			 = "\tPlease enter a number",
				again			= "If you wanna redo press any number except 0";
				
	/**greetings*/
	cout << wellcome << endl
			 << explanation << endl;
	do
	{
		cout << size << endl;
		lines = 0, cols = 0;
		while ( cin >> side )
		{
			if ( side > 1 && side < 10 )
			{
				if ( lines < 2 ){	lines = side;	}
				else if ( cols < 2 )
				{ cols = side; break; }
			}	else	{
				cout << valid << endl;
			}
		}
		
		incaMatrix( lines, cols );
		
		cout << again << endl;
		cin >> baby;//is it mommy?
		/**Could be added functionalities here, but it's just a demo*/
	}	while ( cin >> baby );
	return 0;
};

void incaMatrix ( int line, int col )
{
	int counter = 1, i = 0, j = 0;
	static int total = line*col;
	int inca[ lines ] [ cols ];
	while( TOTAL )
	{
		static int top = 1, left = 0;
		
		/**left to right cols filling*/
		for ( ; j < col && TOTAL; ++j, ++counter )
		{
			inca[ i ] [ j ] = counter;
			if ( j == col-1 )
			{	++i;	--line;	--col;	};
		};
		/**dawnwards line filling*/
		for ( ; i < line && TOTAL; ++i, ++counter )
		{
			inca[ i ] [ j ] = counter;
			if ( i == line-1 ){	--j;	};
		};
		/**right to left col filling*/
		for ( ; j >= left && TOTAL ; --j, ++counter )
		{
			inca[ i ] [ j ] = counter;
			if ( j == left ){	--i;	};
		};
		/**upwards line filling*/
		for ( ; i >= top && TOTAL; --i, ++counter )
		{
			inca[ i ] [ j ] = counter;
			if ( i == top )
			{	++j;	++top;	++left;	};	
		};
	};
	//printing
	for ( i = 0; i < lines; ++i )
	{
		for ( j = 0; j < cols; ++j )
		{
			cout << inca[ i ] [ j ] << "\t";
		};
		cout << endl;
	};
};
/**
	It could be easily extended with more functionalities, eg: reversed, multiple
constructions, ... in a class and more well done through an template but 
languages have many different approches in classes and just a few support 
generic programming.

PS: Intensonally i used javadoc comments pattern
*/