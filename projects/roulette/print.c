#include "roulette.h"

void print_instructions(void)
{
	printf(
		   "Welcome to Roulette!\n"
		   "You have a starting balance of %d dollars\n"
			"Place a bet on either:\n"
			"Even numbers (e),\n"
			"Odd numbers (o),\n"
			"A single number.\n"
		    "Or enter 'h' to display help.\n\n", START_BALANCE);
}

void print_help(void)
{
	printf("\n%s\n",
		   "Valid inputs:\n"
		   "h    to show help,\n"
		   "q    to quit,\n"
		   "e    to bet on an even number,\n"
		   "o    to bet on an odd number,\n"
		   "or enter any integer from 0 to 35.\n"
		  );
}

void print_game_status(int balance)
{
	printf("\nCurrent game status:\n"
			"Balance: %d\n\n", balance);
}

void print_final_game_status(int balance)
{
	printf("\nFinal game result:\n"
			"Balance: %d\n", balance);
	if (balance > START_BALANCE) {
		printf("You made %d dollars! :)\n\n", balance - START_BALANCE);
	}
	else if (balance == START_BALANCE) {
		printf("You broke even :|\n\n");
	}
	else {
		printf("You lost %d dollars :(\n\n", START_BALANCE - balance);
	}
}
