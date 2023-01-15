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
        int now = (a + b) % 24;
        cout << "#" << i << " " << now << '\n';
    }
}