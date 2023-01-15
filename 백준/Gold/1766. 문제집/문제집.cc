#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
int used[32001];
vector<int> arr[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        used[b]++;
        arr[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (used[i] == 0) pq.push(i);
    }

    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();

        cout << now << " ";

        for (int i = 0; i < arr[now].size(); i++){
            int newnow = arr[now][i];
            used[newnow]--;

            if (used[newnow] == 0) pq.push(newnow);
        }
    }
    
}