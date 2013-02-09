/* Testing to see the preprocessor's reaction to a macro 
 * producing infinite recursion. */
 
#define forever(x) forever(forever(x))
forever(more)
