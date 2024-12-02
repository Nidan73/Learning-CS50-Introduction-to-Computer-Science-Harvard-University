#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_numbers;
    do
    {
     card_numbers = get_long("Numbers: ");
    }
    while(card_numbers < 1);

    long number = card_numbers;
    int sum = 0;
    int count = 0;

    while(number > 0 )
    {

        int digit = number%10;

        if( count % 2 == 0)
         {
                 sum = sum+digit;
         }
        else
        {
            int product = digit*2;

            if( product > 9)
            {
                 sum += product-9 ;
            }

            else
            {
                 sum += product;
            }

        }
         number /=10;
         count++;

    }

    bool is_valid = (sum % 10 == 0);
    int len = count ;

    long start_digit = card_numbers;


    while (start_digit >= 100)
    {
    start_digit /= 10;
    }

     string card_type = "INVALID";

     if (is_valid)
     {
     if ((len == 15) && (start_digit == 34 || start_digit == 37))
        {
            card_type = "AMEX";
        }
        else if ((len == 16) && (start_digit >= 51 && start_digit <= 55))
        {
            card_type = "MASTERCARD";
        }
        else if ((len == 13 || len == 16) && (start_digit / 10 == 4))
        {
            card_type = "VISA";
        }

    }
    printf("%s\n",card_type);

}
