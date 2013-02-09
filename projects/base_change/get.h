/*
 * get.h
 *
 */

//Gets a base number from the user.
int get_start_base();

//Gets a base number from the user.
int get_end_base();

/* Gets an integer from the user from lowest to highest values. */
int get_int(const char *prompt, int lowest, int highest);

//Gets a number from the user in the given base.
int get_num(int base);

//Gets a number string from the user and returns its decimal int value.
int get_num_as_string(int start_base);

//Gets and returns a number string from the user.
num_string get_num_string(int *length);

//Returns the numeric int value of a number character.
int symbol_val(char c);
