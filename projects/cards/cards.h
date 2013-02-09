/* Header file for the cards project. */

#include <stdio.h>
#include <stdlib.h>

//Enumeration type for the card values (pips):
enum pips {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
//Enumeration type for the card suits:
enum suit {spade = 1, heart, club, diamond};

//Create mnemonic types for pips and suit:
typedef enum pips pips;
typedef enum suit suit;

int* check_pips(int n, pips p[]);
void draw_cards(int n);
void check_three_of_a_kind(int n, pips p[]);
void check_four_of_a_kind(int n, pips p[]);
void check_full_house(int n, pips p[]);
void check_straight(int n, pips p[]);
pips* has_straight(int n, pips p[]);
void print_card(pips p, suit s);
void print_hand(int n, pips p[], suit s[]);
void print_straight(pips straight[]);
void print_flush(pips flush[], suit s);
char* pips_name(pips p);
char* suit_name(suit s);
