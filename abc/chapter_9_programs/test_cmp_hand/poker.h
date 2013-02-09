/* Header file for the Poker project. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Suits for the cards.
typedef enum {clubs, diamonds, hearts, spades} suit;

//Poker hand types (also used as scores).
typedef enum {high_card = 0, pair, two_pair, three_kind, straight, flush,
	full_house, four_kind, straight_flush} pkr_hand;

//A card.
typedef struct {
    int rank;
    suit suit;
} card;

//In print.c
void print_cards(card *c_ptr, int n);
void print_data(pkr_hand type, int n_deals, int hand_cnt);
void print_rank_name(int rank);
char *suit_name(suit s);
char *hand_name(pkr_hand type);

//In cmp.c
int cmp_hands(card hand1[], card hand2[]);
int cmp_same_hands(card hand1[], card hand2[]);;
int cmp_card(const void *vp, const void *vq);

//In check.c
int is_straight_flush(card h[5]);
int is_four_kind(card h[5]);
int is_full_house(card h[5]);
int is_flush(card h[5]);
int is_straight(card h[5]);
int is_three_kind_n(card h[], int n);
int is_three_kind(card h[5]);
int is_two_pair(card h[5]);
int is_pair_n(card h[], int n);
int is_pair(card h[5]);

//In setup.c
card assign_values(int rank, suit suit);
void swap(card *p, card *q);
void create_deck(card deck[52]);
void shuffle(card deck[52]);
void deal_the_cards(card deck[52], card hand[5]);
pkr_hand score_hand(card hand[5]);

//In play.c
void play_poker(card deck[52], int n_deals);


