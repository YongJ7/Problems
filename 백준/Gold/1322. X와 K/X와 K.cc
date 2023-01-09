#include <iostream>
using namespace std;
typedef long long int ll;
ll X, K, ans;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> X >> K;

    for (int i = 0, j = 0;; i++)
    {
        if (!((X >> i) & 1))
        {
            ans |= ((K >> j) & 1) << i;
            j++;
            if (!(K >> j))
                break;
        }
    }
    cout << ans;
}