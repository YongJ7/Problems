#include <iostream>
using namespace std;
int T;
pair<int, int> fibo[41];
int main()
{
    cin >> T;
    fibo[0] = {1, 0};
    fibo[1] = {0, 1};
    for (int i = 2; i <= 40; i++)
    {
        int f = fibo[i - 2].first + fibo[i - 1].first;
        int s = fibo[i - 2].second + fibo[i - 1].second;
        fibo[i] = {f, s};
    }
    for (int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        cout << fibo[a].first << " " << fibo[a].second << '\n';
    }
}