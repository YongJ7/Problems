#include <iostream>
using namespace std;
int T;
int fibo[46];
int main()
{
    cin >> T;
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 45; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    cout<<fibo[T];
}