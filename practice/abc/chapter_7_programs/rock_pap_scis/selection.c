#include "r_p_s.h"

r_p_s selection_by_machine(void)
{
	return ((r_p_s) (rand() % 3));
}

r_p_s selection_by_player(void)
{
	char c;
	r_p_s player_choice;
	
	printf("\nInput r, p, or s:  ");
	while (isspace(c = getchar()));
	switch(c) {
		case 'r':
			player_choice = rock;
			break;
		case 'p':
			player_choice = paper;
			break;
		case 's':
			player_choice = scissors;
			break;
		case 'g':
			player_choice = game;
			break;
		case 'i':
			player_choice = instructions;
			break;
		case 'q':
			player_choice = quit;
			break;
		default:
			player_choice = help;
			break;
	}
	return player_choice;
}
