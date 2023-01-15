#include <iostream>
using namespace std;
int N, ans;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    ans += (N / 5 + N / 25 + N / 125);
    cout << ans;
}