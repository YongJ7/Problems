#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    int N, end, begin;

    vector<pair<int, int>> schedule;
    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> begin >> end;
        schedule.push_back(make_pair(begin, end));
    }

    sort(schedule.begin(), schedule.end());

    pq.push(schedule[0].second);

    for (int i = 1; i < N; i++)
    {
        if (pq.top() <= schedule[i].first)
        {
            pq.pop();
            pq.push(schedule[i].second);
        }
        else{
            pq.push(schedule[i].second);
        }
    }

    cout << pq.size();
}