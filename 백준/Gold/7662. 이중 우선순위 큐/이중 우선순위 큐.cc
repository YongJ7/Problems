#include <bits/stdc++.h>
using namespace std;

priority_queue<int> MAX_pq; // 최대 힙
priority_queue<int, vector<int>, greater<int> > MIN_pq; // 최소 힙

map<int, int> num; // 정수 개수

int T, k, x, now; // 테스트케이스, 연산의 개수, 입력 숫자
char INST; // 연산 문자

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;
    for (int test_case = 0; test_case < T; test_case++) {
        cin >> k;
        while (!MAX_pq.empty()) MAX_pq.pop();
        while (!MIN_pq.empty()) MIN_pq.pop();
        num.clear();

        for (int i = 0; i < k; i++) {
            cin >> INST >> x;
            if (INST == 'I') {
                MAX_pq.push(x);
                MIN_pq.push(x);
                num[x]++;
            }
            else {
                if (x == 1) {
                    while (!MAX_pq.empty() && num[MAX_pq.top()] == 0) MAX_pq.pop();

                    if (!MAX_pq.empty())
                    {
                        num[MAX_pq.top()]--;
                        MAX_pq.pop();
                    }
                }
                else if (x == -1) {
                    while (!MIN_pq.empty() && num[MIN_pq.top()] == 0) MIN_pq.pop();

                    if (!MIN_pq.empty())
                    {
                        num[MIN_pq.top()]--;
                        MIN_pq.pop();
                    }
                }
            }
        }
        while (!MAX_pq.empty() && num[MAX_pq.top()] == 0) MAX_pq.pop();
        while (!MIN_pq.empty() && num[MIN_pq.top()] == 0) MIN_pq.pop();

        if (MAX_pq.empty() || MIN_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << MAX_pq.top() << " " << MIN_pq.top() << '\n';
        }
    }
}