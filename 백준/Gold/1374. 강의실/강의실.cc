#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    //freopen("input.txt","r",stdin);
    int N, num, end, begin;
    
    vector<pair<int, int>> schedule;  // 모든 일정 시작과 끝 시간 저장
    priority_queue<int, vector<int>, greater<int> > pq;  // 끝나는 시간 오름차순 저장

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num >> begin >> end;
        schedule.push_back(make_pair(begin, end));
    }

    sort(schedule.begin(), schedule.end());

    pq.push(schedule[0].second);  // 가장 먼저 시작 하는 강의의 끝나는 시간을 저장
    
    // 강의 시작 시간에 대해서 오름 차순으로 저장 된 배열을 탐색하여 다음 강의가 시작할 때 가장 먼저 끝나는 강의실을 사용할 수 있는지 없는지 판별
    for (int i = 1; i < N; i++)
    {
        if (pq.top() <= schedule[i].first)  // 다음 강의 시작 시간이 현재 강의가 끝난 이후라면 현 강의를 지우고 다음 강의 끝 시간 저장
        {
            pq.pop();
            pq.push(schedule[i].second);
        }
        else{  // 강의 중간에 시작해야 한다면 새로운 강의실을 열고 끝 시간 저장
            pq.push(schedule[i].second);
        }
    }

    cout << pq.size(); // 남은 강의가 결국 필요한 강의실 수
}