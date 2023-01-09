#include <iostream>
#include <stack>

using namespace std;

int arr[1000010];
int ans[1000010];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    stack<int> s;

    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}