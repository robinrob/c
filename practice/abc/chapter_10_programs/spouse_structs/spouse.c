/* Mutually dependent struct definitions ... */

struct husband {
	int age;
	char name[10];
	struct wife *spouse;
} a;

struct wife {
	int age;
	char name[10];
	struct husband *spouse;
} b;


