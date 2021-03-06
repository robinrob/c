/* Header file for typedefs. */

typedef struct {
	char *name;
	int age;
	int weight;
} DATA;

struct NODE {
	DATA data;
	struct NODE *next;
};

/* Sorting keys. */
typedef enum {age, name, weight} sort_key;

/* Boolean values */
typedef enum {true, false} boolean;

/* Ease-of-use typedef */
typedef struct NODE NODE;
