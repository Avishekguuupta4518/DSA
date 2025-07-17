#include <stdio.h>
#include <time.h>

void towerOfHanoi(int n, char src, char temp, char dst)
{ 
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", src, dst);
        return;
    }
    towerOfHanoi(n - 1, src, dst, temp);

    printf("Move disk %d from %c to %c\n", n, src, dst);

    towerOfHanoi(n - 1, temp, src, dst);
}

int main()
{
    int n;
    double diff;
    clock_t start, end;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    start = clock();
    towerOfHanoi(n, 'A', 'B', 'C');
    end = clock();
    diff = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time taken is %lf seconds\n", diff);
    return 0;
}