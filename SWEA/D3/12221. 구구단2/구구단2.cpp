#include <iostream>
using namespace std;
int T;
int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a <= 9 && b <= 9)
        {
            cout << "#" << i << " " << a * b << '\n';
        }
        else
        {
            cout << "#" << i << " " << -1 << '\n';
        }
    }
}