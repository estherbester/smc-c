/*


*/


#include <stdio.h>
#include <math.h>


/* uses formula given below to calculate the monthly payment */
double calc_monthly(double principal, double interest_rate, int years)
{
    double monthly_pay;
    int months = years * 12;

    interest_rate = interest_rate/1200;

    // Monthly Pay=[ rate +  rate /([1+rate]^months -1)] X principle
    monthly_pay = pow(1+interest_rate, months);
    monthly_pay = monthly_pay - 1;
    monthly_pay = interest_rate/monthly_pay;
    monthly_pay = interest_rate + monthly_pay;
    monthly_pay = monthly_pay * principal;

    return monthly_pay;
}

/* returns total amount paid over the term of the loan,
   given the monthly payment */
double calc_total(double monthly, int years)
{
    return monthly * (years * 12);
}

int main(void){
    double principal, interest_rate, monthly, total_paid;
    int   years;


    printf("Enter your principal: ");
    scanf("%lf", &principal);
    printf("Enter your interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter your term in years: ");
    scanf("%d", &years);

    /* using nicely formatted numbers to return figures */
    monthly = calc_monthly(principal, interest_rate, years);
    printf("Your monthly payment is: %.2lf\n", monthly);

    total_paid = calc_total(monthly, years);

    printf("Your total payment over %d months will be: %.2lf\n", years*12, total_paid);
    printf("You will pay %.2lf total in interest\n", (total_paid-principal));
    return 0;
}
