#include <iostream>
using namespace std;
int k;
int B[50];
int main()
{
    cin >> k;
    B[0] = 0;
    B[1] = 1;
    B[2] = 1;
    for (int i = 3; i <= 45; i++)
    {
        B[i] = B[i - 1] + B[i - 2];
    }
    cout << B[k - 1] << " " << B[k];
}