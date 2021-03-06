/* Header file for sorting functions. */

/* Bubble-sorts a list of DATA values using the
 * specified sorting key.
 */
void bubb_sort_list(NODE *list, sort_key key, void comp_func(NODE *, sort_key));

/* Compares the data stored in the given node
 * and the next one using the specified key value.
 * The values are swapped if they are out of order.
 */
void compare(NODE *n, sort_key key);

/* Swaps the data values of two nodes. */
void swap(NODE *n1, NODE *n2);
