#include<stdio.h>

long int sum(int n)
{
    if(n == 1)
       return 1;
    else 
       return n+sum(n-1);   
}

int main()
{
    long int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = sum(num);
    printf("The sum of %d is %d.\n", num, result);
    return 0;
}

