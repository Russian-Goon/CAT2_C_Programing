
/*
Name: SAMMY KIOKO KAMENE
Reg No: CT101/G/26524/25
Date:6/11/2025
Description: A C program to calculate gross pay, taxes, and net pay
             based on hours worked and hourly wage.
*/

#include <stdio.h>

int main() {
    float hours, wage, grossPay, tax, netPay;

    // Input hours worked and hourly wage
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    printf("Enter hourly wage: ");
    scanf("%f", &wage);

    // Calculate gross pay (including overtime)
    if (hours > 40)
        grossPay = (40 * wage) + ((hours - 40) * wage * 1.5);
    else
        grossPay = hours * wage;

    // Calculate tax
    if (grossPay <= 600)
        tax = 0.15 * grossPay;
    else
        tax = (0.15 * 600) + (0.20 * (grossPay - 600));

    // Calculate net pay
    netPay = grossPay - tax;

    // Display results
    printf("\n----- PAYSLIP -----\n");
    printf("Gross Pay : $%.2f\n", grossPay);
    printf("Tax       : $%.2f\n", tax);
    printf("Net Pay   : $%.2f\n", netPay);

    return 0;
}
