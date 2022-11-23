#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage); // Put this on top so compiler knows this is a function we neen below

int main(void)
{

    float regular = get_float("Regulat price: ");
    int percent_off = get_int("Percent off: ");
    float sale = discount(regular, percent_off);
    printf("Sale price: %.2f\n", sale);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage)/100; // Not printing, it hands back a value
}