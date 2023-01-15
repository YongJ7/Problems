#include <stdio.h>

int n;
int arr[1000001];
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0)
        {
            arr[i] = arr[i] < arr[i / 2] + 1 ? arr[i] : arr[i / 2] + 1;
        }
        if (i % 3 == 0)
        {
            arr[i] = arr[i] < arr[i / 3] + 1 ? arr[i] : arr[i / 3] + 1;
        }
    }
    printf("%d", arr[n]);
}