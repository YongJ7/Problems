#include <stdio.h>
int N, M;
int arr[101];
int main()
{
    scanf("%d %d", &N, &M);
    int sum = 0;
    int mm = 0;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum > M)
                    continue;
                if (sum == M)
                {
                    mm = sum;
                    printf("%d", mm);
                    return 0;
                }
                if (mm < sum)
                {
                    mm = sum;
                }
            }
        }
    }
    printf("%d", mm);
}