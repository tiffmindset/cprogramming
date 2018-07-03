#include <stdio.h>
#include <stdlib.h>

int isPrime (unsigned num)
{
    int i = 2;
    int isPrime = 1;
    while ((i < num) && (isPrime))
    {
        if (num % i == 0)
            isPrime = 0;
        i = i + 1;
    }
    return isPrime;
}

int main()
{
    int i, n;
    do
    {
        printf("Please enter a positive integer (0 to end):");
        scanf("%d", &n);
        if (n < 0 )
            printf("Invalid Input!\n\n");

        else if (n > 0)
        {
            printf("Prime numbers:");
            for(i=2; i<=n; i=i+1)
            {
                if (isPrime(i))
                    printf("%d, ", i);
            }
            printf("\n\n");

        }
    }while (n!=0);
    printf("Thanks and bye!");

}
