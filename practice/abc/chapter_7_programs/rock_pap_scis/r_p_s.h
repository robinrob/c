#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum r_p_s {rock, paper, scissors, game, help, instructions, quit};
enum outcome {win, lose, tie, error};

typedef enum r_p_s r_p_s;
typedef enum outcome outcome;

outcome compare(r_p_s player_choice, r_p_s machine_choice);
void prn_final_status(int win_cnt, int lose_cnt);
void prn_game_status(int win_cnt, int lose_cnt, int tie_cnt);
void print_instructions(void);
void report_and_tabulate(outcome result,
						 r_p_s player_choice, r_p_s machine_choice,
						 int *win_cnt_ptr, int *lose_cnt_ptr, int *tie_cnt_ptr);
r_p_s selection_by_machine(void);
r_p_s selection_by_player(void);
char* choice_name(r_p_s choice);
