#include <stdio.h>
#include <assert.h>

enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
typedef enum month month;
typedef int day;

static int MONTH_ENDS[12] = {31, 28, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31};


day next_day(day d, month m);
month next_month(day d, month m);
void print_month(month m);
int pack_date(int day, int month, int year);
void pack_day(int day, short *date);
void pack_month(int month, short *date);
void pack_year(int year, short *date);
void unpack_date(int date);
int unpack_day(int date);
int unpack_month(int date);
int unpack_year(int date);
int next_date(int date);
