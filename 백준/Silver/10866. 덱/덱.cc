#include <iostream>
#include <deque>
#include <string>
using namespace std;
int N;
deque<int> Q;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        int num;
        cin >> s;
        if (s == "push_back")
        {
            cin >> num;
            Q.push_back(num);
        }
        if (s == "push_front")
        {
            cin >> num;
            Q.push_front(num);
        }
        if (s == "front")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';
        }
        if (s == "back")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }
        if (s == "size")
        {
            cout << Q.size() << '\n';
        }
        if (s == "empty")
        {
            if (Q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        if (s == "pop_front")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
            {
                cout << Q.front() << '\n';
                Q.pop_front();
            }
        }
        if (s == "pop_back")
        {
            if (Q.empty())
                cout << -1 << '\n';
            else
            {
                cout << Q.back() << '\n';
                Q.pop_back();
            }
        }
    }
}