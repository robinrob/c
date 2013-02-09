#include "roulette.h"

int get_winnings(int player_choice, int outlay, int spin)
{
	int winnings = 0;
	if (player_choice >= 0 && player_choice <= 35) {
		if (player_choice == spin) {
			winnings = 36 * outlay;
		}
		else {
			winnings = 0;
		}
	}
	else if (spin == 0) {
		winnings = 0;
	}
	else {
		switch (player_choice) {
			case ODD:
				winnings = ((spin % 2 == 1) ? 2 * outlay : 0);
				break;
			case EVEN:
				winnings = ((spin % 2 == 0) ? 2 * outlay : 0);
				break;
			default:
				printf("Programmer error!\n");
		}
	}
	if (winnings > 0) {
		printf("*** YOU WON %d POUNDS!!! ***\n\n", winnings);
	}
	else {
		printf("You lost your bet.\n\n");
	}
	return winnings;
}
