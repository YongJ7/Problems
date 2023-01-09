#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 1; i <= n; i++)

using namespace std;

int arr[1001][1001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size();
    int l2 = s2.size();

    FOR(i, l1)
    {
        FOR(j, l2)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    cout<<arr[l1][l2]<<'\n';
}