#include <stdio.h>
#include <stdbool.h>

bool primeTest(int num){
    for(int i=num-1; i>1; i--)
        if (num%i==0)
            return false;
    return true;
}

int main(int given_number){
    printf("Enter an integer: ");
    scanf("%d", &given_number);
    if (given_number==1)
        printf ("%d is not a prime number\n", given_number);
    else if (given_number==2 || primeTest(given_number))
        printf ("%d is a prime number\n", given_number);
    else
        printf ("%d is not a prime number\n", given_number);
    return 0;
}

 