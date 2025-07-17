#include<stdio.h>

long int GCD(int a, int b)
{
    if(b == 0)
       return a;
    else 
       return GCD(b, a%b);   
}

int main()
{
    int num1,num2, result;
    printf("Enter a number1: ");
    scanf("%d", &num1);
    printf("Enter a number2: ");
    scanf("%d", &num2);
    result = GCD(num1,num2);
    printf("The GCD  of %d and %d is %d.\n", num1,num2,result);
    return 0;
}

