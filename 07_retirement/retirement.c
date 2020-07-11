#include <stdio.h>
#include <stdlib.h>

//create struct for the retirement info
struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};

//assign typedef to struct
typedef struct _retire_info retire_info;

//function to calculate age (years and months) and balance for print statement
double calculate(int age, double balance, retire_info info) {
    double interest;

    while (info.months > 0) {
        interest = balance * info.rate_of_return;
        balance += (interest + info.contribution);
        age++;

        printf("Age %3d month %2d you have $%.2lf\n", (age/12), (age % 12), balance);
        info.months--;
    }

    return balance;
}

//function for two tasks
void retirement(int startAge, double initial, retire_info working, retire_info retired) {
   
    //define variables
    int currYears;
    int currMonths;
    
    currYears = startAge / 12;
    currMonths = startAge - (currYears * 12);
    
    //print out current balance and age info
    printf("Age %3d month %2d you have $%.2lf\n", currYears, currMonths, initial);
    
    //call calculate function twice for working and retired
    double a = calculate(startAge, initial, working);
    calculate((327 + 489), a, retired);
}

int main()
{
    retire_info working;
    retire_info retired;

    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = (.045 / 12);

    retired.months = 383;
    retired.contribution = -4000;
    retired.rate_of_return = (.01 / 12);

    retirement(327, 21345, working, retired);

    return 0;
}
