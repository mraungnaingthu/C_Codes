//
// Created by Aung Naing Thu on 1/7/2025.
//
#include <stdio.h>

int calculate(int a, char c, int b);

int main() {
    int num1, num2;
    char operator;

    printf("Enter your calculation: ");
    scanf("%d %c %d", &num1, &operator, &num2);

    printf("Result: %d\n", calculate(num1, operator, num2));

    return 0;
}

int calculate(int a, char c, int b) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Error: Division by zero!\n");
                return 0;
            }
        default:
            printf("Error: Invalid operator!\n");
        return 0;
    }
}