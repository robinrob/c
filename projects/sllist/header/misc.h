/* Header file for miscellaneous functions. */

/* Turns a cycling list into a straight & finite list. */
void decycle(NODE *list);

/* Returns a pointer to the NODE at the given list
 * position in the given list. */
NODE *get_node(NODE *list, int pos);

/* Deletes duplicate-valued elements in the list. */
NODE *del_dupl(NODE *list);
