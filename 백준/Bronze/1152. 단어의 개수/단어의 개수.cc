#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char arr[1000000];
    int cnt = 0;
    scanf("%[^\n]", arr);
    int l = strlen(arr);
    if (l == 1 && arr[0] == ' ')
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < l - 1; i++)
    {
        if (arr[i] == ' ')
            cnt++;
    }
    cout << cnt + 1;
}