#include <stdio.h>
#include<cs50.h>

int main(void)
{

   // Prompt user to agree. User char for a single character
   char c = get_char("Do you agree? (y/n) ");

   // Check if user agreed
   if (c == 'y' || c == 'Y') // Use || instead of or, use && instead of and
   {
    printf("Agreed\n");
   }
   else if (c == 'n' || c == 'N') // Need to use single quotes for since characters, different data type needs to match
   {
    printf("Disagreed\n");
   }

}