#include <stdio.h>
#include <time.h>

enum fish {cod, haddock, salmon, trout, prawns};
enum fruit {apple, orange, banana, pear, pineapple};
enum grain {rice, couscous, pasta, bread, spaghetti};
enum meat {pork, beef, chicken, turkey, liver};
enum veg {celery, lettuce, tomato, carrot, potato};

typedef enum fish fish;
typedef enum fruit fruit;
typedef enum grain grain;
typedef enum meat meat;
typedef enum veg veg;

void print_fish(fish f);
void print_fruit(fruit f);
void print_grain(grain g);
void print_meat(meat m);
void print_veg(veg v);
void print_meal(void);

int main(void)
{
	int i;
	srand(time(NULL));
	for (i = 1; i <= 20; ++i) {
		printf("Meal (%d): \n	", i);
		print_meal();
		printf("\n");
	}
	return 0;
}

void print_meal()
{
	print_fish((fish) (rand() % 4) + 1);
	printf(", ");
	print_fruit((fruit) (rand() % 4) + 1);
	printf(", ");
	print_grain((grain) (rand() % 4) + 1);
	printf(", ");
	print_meat((meat) (rand() % 4) + 1);
	printf(", and ");
	print_veg((veg) (rand() % 4) + 1);
}

void print_fish(fish f)
{
	switch (f) {
		case cod:
			printf("cod");
			break;
		case haddock:
			printf("haddock");
			break;
		case salmon:
			printf("salmon");
			break;
		case trout:
			printf("tuna");
			break;
		case prawns:
			printf("prawns");
			break;
		default:
			printf("Programmer error!\n");
			break;
	}
}

void print_fruit(fruit f)
{
	switch (f) {
		case apple:
			printf("apple");
			break;
		case orange:
			printf("orange");
			break;
		case banana:
			printf("banana");
			break;
		case pear:
			printf("pear");
			break;
		case pineapple:
			printf("pineapple");
			break;
		default:
			printf("Programmer error!\n");
			break;
	}
}

void print_grain(grain g)
{
	switch (g) {
		case cod:
			printf("rice");
			break;
		case haddock:
			printf("couscous");
			break;
		case salmon:
			printf("pasta");
			break;
		case trout:
			printf("bread");
			break;
		case prawns:
			printf("spaghetti");
			break;
		default:
			printf("Programmer error!\n");
			break;
	}
}

void print_meat(meat m)
{
	switch (m) {
		case cod:
			printf("pork");
			break;
		case haddock:
			printf("beef");
			break;
		case salmon:
			printf("chicken");
			break;
		case trout:
			printf("turkey");
			break;
		case prawns:
			printf("liver");
			break;
		default:
			printf("Programmer error!\n");
			break;
	}
}

void print_veg(veg v)
{
	switch (v) {
		case celery:
			printf("celery");
			break;
		case lettuce:
			printf("lettuce");
			break;
		case tomato:
			printf("tomato");
			break;
		case carrot:
			printf("carrot");
			break;
		case potato:
			printf("potato");
			break;
		default:
			printf("Programmer error!\n");
			break;
	}
}
