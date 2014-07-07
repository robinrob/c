#include "r_p_s.h"

void report_and_tabulate(outcome result,
						 r_p_s player_choice, r_p_s machine_choice,
						 int *win_cnt_ptr, int *lose_cnt_ptr, int *tie_cnt_ptr)
{
	printf("You chose %s and i chose %s. ",
		   choice_name(player_choice), choice_name(machine_choice));
	switch(result) {
		case win:
			++*win_cnt_ptr;
			printf("%27sYou win.\n", "");
			break;
		case lose:
			++*lose_cnt_ptr;
			printf("%27sYou lose.\n", "");
			break;
		case tie:
			++*tie_cnt_ptr;
			printf("%27sA tie.\n", "");
			break;
		default:
			printf("\nPROGRAMMER ERROR: Unexpected result!\n\n");
			exit(1);
	}
}

char* choice_name(r_p_s choice)
{
	char *name;
	switch(choice) {
		case rock:
			name = "rock";
			break;
		case paper:
			name = "paper";
			break;
		case scissors:
			name = "scissors";
			break;
		default:
			printf("PROGRAMMER ERROR\n");
			exit(1);
	}
	return name;
}
