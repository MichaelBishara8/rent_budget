#include <stdio.h>
#include <stdlib.h>


#define multi 4.3				//Multiplier of 4.3 weeks per month

struct rent{
	float weekly, monthly, yearly;
};

void calc_monthly(float weekly, float *monthly_p){
	*monthly_p = weekly * multi;
}

void calc_weekly(float monthly, float *weekly_p){
	*weekly_p = monthly / multi;
}

int main(int argc, char **argv){
	float input;
	char mod; 				// w = weekly, m = monthly modifier for scanf
	struct rent rent;
	float *weekly_p = &rent.weekly;
	float *monthly_p = &rent.monthly;

	printf("Enter period(w/m) & Amount: ");
	scanf("%c%f", &mod, &input);

	/* Decide if calculating weekly or monthly*/
	if (mod == 'w'){
		*weekly_p = input;
		calc_monthly(input, monthly_p);
	}
	if (mod == 'm'){
		rent.monthly = input;
		calc_weekly(input, weekly_p);
	}

	rent.yearly = rent.monthly*12;

	printf("Estimated weekly: $%.2f\n", rent.weekly);
	printf("Estimated monthly: $%.2f\n", rent.monthly);
	printf("Estimated yearly: $%.2f", rent.yearly);

}

