#include "cards.h"

char* pips_name(pips p)
{
	char *name = "null";
	switch(p) {
		case ace:
			name = "Ace";
			break;
		case two:
			name = "Two";
			break;
		case three:
			name = "Three";
			break;
		case four:
		 	name =  "Four";
			break;
		case five:
			name = "Five";
			break;
		case six:
			name = "Six";
			break;
		case seven:
			name = "Seven";
			break;
		case eight:
			name = "Eight";
			break;
		case nine:
			name = "Nine";
			break;
		case ten:
			name = "Ten";
			break;
		case jack:
			name = "Jack";
			break;
		case queen:
			name = "Queen";
			break;
		case king:
			name = "King";
			break;
		default:
			printf("Programmer error!\n");
			exit(1);
	}
	return name;
}

char* suit_name(suit s)
{
	char *name = "null";
	switch(s) {
		case spade:
			name = "Spades";
			break;
		case heart:
			name = "Hearts";
			break;
		case club:
			name = "Clubs";
			break;
		case diamond:
			name = "Diamonds";
			break;
		default:
			printf("Programmer error!\n");
			exit(1);
	}
	return name;
}

