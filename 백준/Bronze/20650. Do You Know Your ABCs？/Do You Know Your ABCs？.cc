#include <bits/stdc++.h>
using namespace std;
int arr[7];
int main()
{
    int A, B, C;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    A = arr[0];
    B = arr[1];
    C = arr[6] - (A + B);
    cout << A << " " << B << " " << C;

    return 0;
}