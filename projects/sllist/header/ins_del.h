/* Header file for insertion/deletion functions. */

/* Inserts an element into the given list, at the
 * given list position (starting from 1). */
NODE *insert(DATA d, NODE *list, int pos);

/* Deletes an element at the given list position
 * in the given list (starting from 1).
 */
NODE *delete(NODE *list, int pos);
