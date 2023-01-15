#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int N, M;
int binary(int a)
{
    int s = 0;
    int e = N - 1;
    int mid = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a == arr[mid])
            return 1;
        else if (arr[mid] > a)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        cout << binary(a) << '\n';
    }
}