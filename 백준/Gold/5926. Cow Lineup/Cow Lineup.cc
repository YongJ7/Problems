#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N, ans = 2e9;
struct Cow
{
    int X, id;
};

vector<Cow> arr;
map<int, int> Map;
set<int> ID_set;

int comp(Cow a, Cow b)
{
    return a.X < b.X;
}

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Cow c;
        cin >> c.X >> c.id;
        arr.push_back(c);
        ID_set.insert(c.id);
        Map[c.id] = 0;
    }
}

void solve()
{
    sort(arr.begin(), arr.end(), comp);

    int tot_id = ID_set.size();

    int start = 0;
    int end = 0;
    int num_in_map = 0;

    while (1)
    {
        while (num_in_map != tot_id && end < N)
        {
            if (Map[arr[end].id] == 0)
                num_in_map++;
            Map[arr[end++].id]++;
        }
        if (end == N && num_in_map != tot_id)
            break;

        while (Map[arr[start].id] > 1)
            Map[arr[start++].id]--;

        ans = min(ans, arr[end - 1].X - arr[start].X);
        Map[arr[start++].id]--;
        num_in_map--;
    }
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    InputData();

    solve();

    cout << ans << '\n';
}