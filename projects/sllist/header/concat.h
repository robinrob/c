/* Header file for concatenation functions. */

/* Concatenates list2 onto the end of list1,
 * no matter what!
 */
void concat(NODE *list1, NODE *list2);

/* Concatenates list2 onto the end of list1
 * ONLY if the two lists are not equal. If
 * they are equal, the head of list1 is returned.
 * If list1 is NULL, list2 is returned.
 */
NODE *concatenate(NODE *list1, NODE *list2);

/* Returns a concatenated copy of list1 and list2. */
NODE *copy_cat(NODE *list1, NODE *list2);
