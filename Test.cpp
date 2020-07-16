/* Card shuffling and dealing program */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void shuffle( int [] [ 13 ]);

void deal( const int [][ 13 ], const char *[], const char *[]);

int main()
{
	//Storing all suits....
	 const char *suite[ 4 ] = {"Hearts", "Diamonds", "Clubs", "Spades" };
	//SToring all faces
	const char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
	"Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	//Create Deck and initialize with zeros...
	int deck[ 4 ][ 13 ] = { 0 };

	//rand() ..  seeding random values...
	srand( time( 0 ) );

	//Shuffle and store result in deck
	shuffle( deck );

	//Show result on screen...
	deal( deck, face, suite );
	return 0;
}
void shuffle( int wDeck[][13] )
{
	 int row, column, card;
	 for ( card = 1; card <= 52; card++)
		 //For each card...
	 {

	 	//select randomly location in Array
			 do{
					row = rand() % 4;
					column = rand() % 13; 

					}
	 	//search again if some card already present there..
	 	while( wDeck [ row ][ column ] != 0 );

	 	//if space available place card...
	 	wDeck[ row ][ column ] = card;
	}
}
void deal( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[])
{
	 int card, row, column;
	 
	 for ( card = 1; card <= 52; card++ )

			for( row = 0; row <= 3; row++)

				for( column = 0; column <= 12; column++)

						if( wDeck[ row ][ column ] == card )
									cout << card << ". " <<wFace[ column ] << " of " << wSuit [row ] << '\n';
} 