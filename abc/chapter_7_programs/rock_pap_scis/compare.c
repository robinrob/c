#include "r_p_s.h"

outcome compare(r_p_s player_choice, r_p_s machine_choice)
{
	outcome result;
	
	if (player_choice == machine_choice) {
		return tie;
	}
	switch (player_choice) {
		case rock:
			result = (machine_choice == scissors) ? win : lose;
			break;
		case paper:
			result = (machine_choice == rock) ? win : lose;
			break;
		case scissors:
			result = (machine_choice == paper) ? win : lose;
			break;
		default:
			printf("PROGRAMMER ERROR: Unexpected choice!\n\n");
			exit(1);
	}
	return result;
}
