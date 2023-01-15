#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    int a, b;
    a = N / 5;
    while (1)
    {
        if (a < 0)
        {
            cout << -1;
            return 0;
        }
        if ((N - (a * 5)) % 3 == 0)
        {
            b = (N - (a * 5)) / 3;
            break;
        }
        a--;
    }
    cout << a + b;
}