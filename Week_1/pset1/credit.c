#include <cs50.h>
#include <stdio.h>

void checksum(long n);
int counter(long n);

int main(void) 
{
    // Ask user for CC info, must be 13, 15, 16 digits
    int digits = 0;
    do
    {
        long card_num = get_long("Credit Card Number: ");
        digits = counter(card_num);
    }
    while(digits < 13 || digits > 16 || digits == 14);
    printf("Credit card has %i digits\n", digits);
    

    // Checksum - validate card
    // checksum(card_num);


    // Determine which card it is - AMEX, MASTERCARD, VISA or INVALID
}


int counter(long n)
{
    int counter = 0;
    do 
    {
        n /= 10;
        counter++;
    }
    while( n != 0);
    return counter;
}

void checksum(long n)
{
    int digits = counter(n);

    for (int i = 1; i < n; i*10)
    {

    }
}