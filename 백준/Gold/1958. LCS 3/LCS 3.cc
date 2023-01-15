#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FOR(i, n) for (int i = 1; i <= n; i++)

using namespace std;

int arr[101][101][101];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();

    FOR(i, l1)
    {
        FOR(j, l2)
        {
            FOR(l, l3)
            {
                if (s1[i - 1] == s2[j - 1] && s1[i-1] == s3[l-1])
                {
                    arr[i][j][l] = arr[i - 1][j - 1][l-1] + 1;
                }
                else
                {
                    arr[i][j][l] = max(arr[i - 1][j][l], max(arr[i][j - 1][l],arr[i][j][l-1]));
                }
            }
        }
    }
    cout << arr[l1][l2][l3] << '\n';
}