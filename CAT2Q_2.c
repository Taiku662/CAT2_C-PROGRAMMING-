/*
Purity Taiku
CT100/G/2615/25
DES: prompt user his hourly wage*/
#include <stdio.h>

int main() {
    float time, hourlywage;
    float gross_pay, taxes, net_pay;
    
    // Get input from user
    printf("Enter time in a week: ");
    scanf("%f", &time);
    printf("Enter hourly wage: $");
    scanf("%f", &hourlywage);
    
    // Calculate gross pay
    if (time <= 40) {
        gross_pay = time * hourlywage;
    } else {
        float regular_pay = 40 * hourlywage;
        float overtime_pay = (time - 40) * hourlywage * 1.5;
        gross_pay = regular_pay + overtime_pay;
    }
    
    
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;  
    } else {
        
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    }
    
    
    net_pay = gross_pay - taxes;
    
    
    printf("\nPayroll Summary:\n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);
    
    return 0;
}