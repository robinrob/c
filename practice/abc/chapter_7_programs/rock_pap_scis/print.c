#include "r_p_s.h"

void print_final_status(int win_cnt, int lose_cnt)
{
	if (win_cnt > lose_cnt) {
		printf("CONGRATULATIONS - You won!\n\n");
	}
	else if (win_cnt == lose_cnt) {
		printf("A DRAW - You tied!\n\n");
	}
	else {
		printf("SORRY - You lost!\n\n");
	}
}

void print_game_status(int win_cnt, int lose_cnt, int tie_cnt)
{
	printf("\n%s\n%s%4d\n%s%4d\n%s%4d\n%s%4d\n\n",
	"GAME STATUS:",
			"   Win:   ", win_cnt,
			"   Lose:  ", lose_cnt,
			"   Tie:   ", tie_cnt,
			"   Total: ", win_cnt + lose_cnt + tie_cnt);
}

void print_help(void)
{
	printf("\n%s\n",
	"The following characters can be used for input:\n"
			"    r   for rock\n"
			"    p   for paper\n"
			"    s   for scissors\n"
			"    g   print the game status\n"
			"    h   help, print this list\n"
			"    i   reprint the instructions\n"
			"    q   quit this game\n");
}

void print_instructions(void)
{
	printf("\n%s\n",
		   "ROCK, PAPER, SCISSORS:\n"
				   "   In this game r is for \"rock,\" p is for \"paper,\" and"
				   " s is for \"scissors.\"\n"
				   "   Both the player and the machine\n"
				   "   will choose one of r, p or s."
				   "  If the two choices are the same,\n"
				   "   then the game is a tie. Otherwise:,\n"
				   "     \"rock breaks the scissors\" (a win for rock),\n"
				   "     \"paper covers the rock\"    (a win for paper),\n"
				   "     \"scissors cut the paper\"   (a win for scissors),\n"
				   "\n"
				   "   There are other allowable inputs:\n"
				   "     g   for game status   (the numer of wins so far),\n"
				   "     h   for help\n"
				   "     i   for instructions  (reprint these instructions),\n"
				   "     q   for quit          (to quit the game.\n"
				   "\n"
				   "   This game is played repeatedly until q is entered.\n"
				   "\n"
				   "   Good luck!\n");
}

