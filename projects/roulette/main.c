/* A roulette game. */

#include "roulette.h"

int main(void)
{
	char input[MAX_STRING];
	int player_choice, spin, outlay, balance = START_BALANCE;
	srand(time(NULL));
	print_instructions();
	while ((player_choice = bet_by_player(&outlay, balance)) != QUIT) {
		if (player_choice >= 0 && player_choice <= 35) {
			balance -= outlay;
			spin = wheel_spin();
			balance += get_winnings(player_choice, outlay, spin);
		}
		else {
			switch (player_choice) {
				case ODD:
				case EVEN:
					balance -= outlay;
					spin = wheel_spin();
					balance += get_winnings(player_choice, outlay, spin);
					break;
				case GAME:
					print_game_status(balance);
					break;
				case HELP:
					print_help();
					break;
				default:
					printf("Programmer error! - cannot get to here!\n");
					exit(1);
			}
		}
		if (balance == 0) {
			break;
		}
	}
	print_final_game_status(balance);
	return 0;
}
