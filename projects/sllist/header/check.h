/* Header file for checking functions. */

/* Checks to see if the two lists are equal. */
boolean check_equal_lists(NODE *list1, NODE *list2);

/* Checks to see if two DATA structures are equal or not. */
boolean check_equal_data(DATA d1, DATA d2);

/* Checks to see whether a list is a cycle. */
boolean check_cycle(NODE *list);
