#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define BLACK 98
#define EVEN 101
#define GAME 103
#define HELP 104
#define ODD 111
#define QUIT 113
#define RED 114
#define MAX_STRING 2
#define START_BALANCE 1000

int bet_by_player(int *outlay_ptr, int balance);
int wheel_spin(void);
int parse_int(char s[], int n);
int compare(int player_choice, int spin);
void print_result(int result);
void report_and_tabulate(int result, int *win_cnt_ptr, int *lose_cnt_ptr, int *balance_ptr);
