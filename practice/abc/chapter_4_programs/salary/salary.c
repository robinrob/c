/* Computes salary & tax blah blah blah. */

#include <stdio.h>

#define WITHHOLD_TAX 0.17
#define STATE_TAX 0.3

int main(void)
{
	double salary, total_salary = 0.0,
		   total_taxes = 0.0, withholding_tax, state_tax;

	while (scanf("%lf", &salary) == 1) {
		withholding_tax = salary * WITHHOLD_TAX;
		state_tax = salary * STATE_TAX;
		total_taxes += state_tax + withholding_tax;
		salary -= (withholding_tax + state_tax);
		total_salary += salary;
		printf("%20s%lf\n%20s%lf\n%20s%lf\n",
				"salary: ", salary,
				"state tax: ", state_tax,
				"withholding tax: ", withholding_tax);
	}
	printf("%20s%lf\n%20s%lf\n",
				"total salary: ", total_salary,
				"total taxes: ", total_taxes);

	return 0;
}
