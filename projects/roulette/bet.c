#include "roulette.h"

int bet_by_player(int *outlay_ptr, int balance)
{
	char input[MAX_STRING];
	int player_choice;
	printf("Your balance: %d\n", balance);
	printf("Enter choice: ");
	scanf("%s", input);
	player_choice = parse_int(input, MAX_STRING);
	if (player_choice >= 0 && player_choice <= 35) {
		*outlay_ptr = get_stake(balance);
		return player_choice;
	}
	else {
		switch(player_choice) {
			case EVEN:
			case ODD:
			case RED:
			case BLACK:
				*outlay_ptr = get_stake(balance);
				break;
		}
	}
	return player_choice;
}

int get_stake(int balance)
{
	int outlay = 0;
	printf("Enter stake: ");
	scanf("%d", &outlay);
	if ((balance - outlay) < 0) {
		outlay = balance;
	}
	return outlay;
}

int wheel_spin(void)
{
	int spin = (rand() % 36);
	printf("Wheel spin: %d\n", spin);
	return spin;
}

int parse_int(char s[], int n)
{
	int i, factor = 1, a = 0;
	for (i = n - 1; i >= 0; --i) {
		if (s[i] != '\0') {
			if (s[i] >= '0' && s[i] <= '9') {
				a += ((s[i]) - '0') * factor;
				factor *= 10;
			}
			else {
				a += (s[i]);
			}
		}
	}
	return a;
}
