#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 3; i <= n; i+=3)

using namespace std;

int arr[3001][3001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.length();
    int l2 = s2.length();

    FOR(i, l1)
    {
        FOR(j, l2)
        {
            if (s1.substr(i-3,3) == s2.substr(j-3,3))
            {
                arr[i][j] = arr[i - 3][j - 3] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i - 3][j], arr[i][j - 3]);
            }
        }
    }
    cout<<arr[l1][l2]<<'\n';
}