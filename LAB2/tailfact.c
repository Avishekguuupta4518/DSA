#include<stdio.h>

int tailfact(int a, long int n)
{
    if(n == 0)
       return a;
    else 
       return tailfact(n * a, n - 1);   
}

int main()
{
    long int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = tailfact(1, num);
    printf("The factorial of %d is %d.\n", num, result);
    return 0;
}

