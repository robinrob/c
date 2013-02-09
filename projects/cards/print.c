#include "cards.h"

void print_hand(int n, pips p[], suit s[])
{
	for (--n; n >= 0; --n) {
		print_card(p[n], s[n]);
	}
}

void print_card(pips p, suit s)
{
	printf("%s of %s\n", pips_name(p), suit_name(s));	
}

void print_straight(pips straight[5])
{
	int i;
	printf("\n%s\n%s", "*** STRAIGHT!!! ***", "You have: ");
	for (i = 4; i >= 0; --i) {
		printf("%s%c ", pips_name(straight[i]), (i > 0) ? ',' : '.');
	}
	printf("\n");
}

void print_flush(pips flush[5], suit s)
{
	int i;
	printf("\n%s\n%s", "*** FLUSH!!! ***", "You have: ");
	char *st_name = suit_name(s);
	for (i = 4; i >= 0; --i) {
		printf("%s%c ", pips_name(flush[i]), (i > 0) ? ',' : '\0');
	}
	printf("of %s.\n", st_name);;
}
