#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;
vector<pair<int, int>> second_line(1000001);

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int now; cin >> now;
        arr.push_back(now);
    }

    if (N == 1) second_line[arr[0]] = { 0,0 };
    else {
        second_line[arr[0]] = { arr[N - 1],arr[1] };
        for (int i = 1; i < N-1; i++) {
            second_line[arr[i]] = { arr[i - 1],arr[i + 1] };
        }
        second_line[arr[N - 1]] = { arr[N - 2],arr[0] };
    }
        
    string INST;
    for (int t = 0; t < M; t++) {
        cin >> INST;
        if (INST == "BN") {
            int i, j, next; cin >> i >> j;
            next = second_line[i].second;
            cout << next << '\n';

            second_line[j] = { i, next };
            second_line[i].second = j;
            second_line[next].first = j;
        }
        else if (INST == "BP") {
            int i, j, before; cin >> i >> j;
            before = second_line[i].first;
            cout << before << '\n';

            second_line[i].first = j;
            second_line[j] = { before,i };
            second_line[before].second = j;
        }
        else if (INST == "CN") {
            int i; cin >> i;
            auto next = second_line[second_line[i].second];
            cout << second_line[i].second << '\n';

            second_line[next.first].second = next.second;
            second_line[next.second].first = next.first;
        }
        else if (INST == "CP") {
            int i; cin >> i;
            auto before = second_line[second_line[i].first];
            cout << second_line[i].first << '\n';

            second_line[before.first].second = before.second;
            second_line[before.second].first = before.first;
        }
    }
}