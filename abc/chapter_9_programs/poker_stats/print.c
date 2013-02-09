#include "poker.h"

//Displays the given hand.
void print_cards(card *c_ptr, int n)
{
	int i;

    for (i = 0; i < n; ++i) {
    	printf("%s of %s\n",
    			rank_name(c_ptr[i].suit),
    			suit_name(c_ptr[i].suit));
    }
    printf("%s%s%s\n\n", "(", hand_name(hand_value(c_ptr)), ")");
}

//Displays the count and probability data for a given hand type.
void print_data(pkr_hand hand, int n_deals, int hand_cnt)
{
	extern double hand_probs[];
	printf("\n%28s%s%d\n%30s%.6lf\n%30s%.6lf\n",
			hand_name(hand), ": ", hand_cnt,
			"empirical probability: ", (double) hand_cnt / n_deals,
			"theoretical probability: ", hand_probs[hand]);
}

//Returns the name of the card suit for a given enum suit value.
char *suit_name(suit s)
{
    if (s == clubs)
    	return "clubs";
    else if (s == diamonds)
    	return "diamonds";
    else if (s == hearts)
    	return "hearts";
    else if (s == spades)
    	return "spades";
    return "NULL";
}

//Returns the name of the card rank for a given enum rank value.
char* rank_name(rank r)
{
	char *name = "NULL";
	switch(r) {
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
		case ace:
			name = "Ace";
			break;
		default:
			printf("Programmer error!\n");
			exit(1);
	}
	return name;
}

//Returns the name of the Poker hand corresponding to the given hand type.
char *hand_name(pkr_hand hand)
{
	char *name = "NULL";
	switch(hand) {
	case 0:
		name = "High card";
		break;
	case 1:
		name = "Pair";
		break;
	case 2:
		name = "Two-pair";
		break;
	case 3:
		name = "Three-of-a-kind";
		break;
	case 4:
		name = "Straight";
		break;
	case 5:
		name = "Flush";
		break;
	case 6:
		name = "Full house";
		break;
	case 7:
		name = "Four-of-a-kind";
		break;
	case 8:
		name = "Straight flush";
		break;
	default:
		printf("Programmer error!\n");
		exit(1);
		break;
	}
	return name;
}

//Returns the name of the rank of a card.
void print_rank_name(int rank)
{
	if (rank == 14) {
		printf("Ace");
	}
	else if (rank == 13) {
		printf("King");
	}
	else if (rank == 12) {
		printf("Queen");
	}
	else if (rank == 11) {
		printf("Jack");
	}
	else if (rank == 10) {
		printf("10");
	}
	else if (rank >= 2 && rank <= 9) {
		putchar('0' + rank);
	}
}
