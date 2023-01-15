#include <stdio.h>
int N;
int SUM(int a)
{
    int arr[100] = {0};
    int sum = a;
    int idx = 0;
    while (a)
    {
        arr[idx++] = a % 10;
        a /= 10;
    }
    for (int i = 0; i < idx; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= 1000000; i++)
    {
        if (SUM(i) == N)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}