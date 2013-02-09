/* A program to demonstrate using enumeration types and structures by
 * creating a meal consisting of four different food types from
 * a menu.
 */

#include <stdio.h>
#include <stdlib.h>

enum food_type {meat, fruit, vegetable, dairy};
typedef enum food_type food_type;

typedef struct {
    char *name;
    food_type type;
    int cals;
    int price;
} food;

void print_food(food f);
char *food_type_name(food_type t);
void create_menu(food menu[]);
void create_meal(food menu[], food meal[]);
int total_cals(food meal[]);
int total_price(food meal[]);

//Main function.
int main(void)
{
    int i;
    food menu[8], meal[4];
    
    create_menu(menu);
    srand(time(NULL));
    create_meal(menu, meal);
    
    printf("A meal:\n");
    for (i = 0; i < 4; ++i) {
	print_food(meal[i]);
    }
    printf("%s%d\n%s%d\n",
	   "Total calories: ", total_cals(meal),
	   "Total price: ", total_price(meal));
	
    return 0;
}

//Prints details of a food item.
void print_food(food f)
{
    printf("%10s%s\n%10s%s\n%10s%d\n%10s%d\n\n",
	   "name: ", f.name, "type: ", food_type_name(f.type),
	   "calories: ", f.cals, "price: ", f.price);
}

//Returns the name corresponding to the food type value.
char *food_type_name(food_type t)
{
    char *name;
    switch(t) {
	case meat:
	    name = "meat";
	    break;
	case fruit:
	    name = "fruit";
	    break;
	case vegetable:
	    name = "vegetable";
	    break;
	case dairy:
	    name = "dairy";
	    break;
	default:
	    printf("Programmer error!\n");
	    exit(1);
    }
    return name;
}

//Creates a menu in the given array.
void create_menu(food menu[]) {
    menu[0].name = "Apple";
    menu[0].type = fruit;
    menu[0].cals = 100;
    menu[0].price = 35;
    
    menu[1].name = "Banana";
    menu[1].type = fruit;
    menu[1].cals = 120;
    menu[1].price = 20;
    
    menu[2].name = "Bacon";
    menu[2].type = meat;
    menu[2].cals = 300;
    menu[2].price = 150;
    
    menu[3].name = "Chicken";
    menu[3].type = meat;
    menu[3].cals = 250;
    menu[3].price = 150;
    
    menu[4].name = "Potatoes";
    menu[4].type = vegetable;
    menu[4].cals = 200;
    menu[4].price = 80;
    
    menu[5].name = "Carrots";
    menu[5].type = vegetable;
    menu[5].cals = 180;
    menu[5].price = 70;
    
    menu[6].name = "Eggs";
    menu[6].type = dairy;
    menu[6].cals = 140;
    menu[6].price = 100;
    
    menu[7].name = "Cheese";
    menu[7].type = dairy;
    menu[7].cals = 150;
    menu[7].price = 120;
}

//Creates a meal using the given menu and meal arrays.
void create_meal(food menu[], food meal[]) {
    int i;
    for (i = 0; i < 4; ++i) {
	meal[i] = menu[i * 2 + rand() % 2];
    }
}

//Calculates the total calories in the meal.
int total_cals(food meal[])
{
    int i, sum = 0;
    for (i = 0; i < 4; ++i) {
	sum += meal[i].cals;
    }
    return sum;
}

//Calculates the total price of the meal.
int total_price(food meal[])
{
    int i, sum = 0;
    for (i = 0; i < 4; ++i) {
	sum += meal[i].price;
    }
    return sum;
}
