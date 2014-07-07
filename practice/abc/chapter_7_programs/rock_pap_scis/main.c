#include "r_p_s.h"

int main (void)
{
	int win_cnt = 0, lose_cnt = 0, tie_cnt = 0;
	outcome result;
	r_p_s player_choice, machine_choice;
	
	srand(time(NULL));
	print_instructions();
	while ((player_choice = selection_by_player()) != quit) {
		switch(player_choice) {
			case rock:
			case paper:
			case scissors:
				machine_choice = selection_by_machine();
				result = compare(player_choice, machine_choice);
				report_and_tabulate(result, player_choice, machine_choice,
									&win_cnt, &lose_cnt, &tie_cnt);
				break;
			case game:
				print_game_status(win_cnt, lose_cnt, tie_cnt);
				break;
			case instructions:
				print_instructions();
				break;
			case help:
				print_help();
				break;
			default:
				printf("\nPROGRAMMER ERROR: Cannot get to here!\n\n");
				exit(1);
		}
	}
	print_game_status(win_cnt, lose_cnt, tie_cnt);
	print_final_status(win_cnt, lose_cnt);
	return 0;
}
