#include<stdio.h>
#define MAX 100

long int table[MAX] = {0};

long int fibo (int n){
    if (n == 0 || n ==1)
       return 1;
    else{
        if(table[n] == 0){
            table[n] = fibo(n-1) + fibo(n-2);
        }
    }
    return table[n];
}

int main()
{
    long int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = fibo(num);
    printf("The fibo of %d is %d.\n", num, result);
    return 0;
}