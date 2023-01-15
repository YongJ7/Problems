#include <iostream>
#include <algorithm>

using namespace std;

struct flower
{
    int s, e;
};
flower map[100010];
int N, ans = 1;
int calc_day(int month, int date)
{
    int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for (int i = 0; i < month; i++)
    {
        sum += day[i];
    }
    sum += date;

    return sum;
}

bool comp1(flower a, flower b)
{
    return a.e > b.e;
}
bool comp2(flower a, flower b)
{
    if (a.s == b.s)
        return a.e < b.e;
    return a.s < b.s;
}
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        map[i] = {calc_day(s1, s2), calc_day(e1, e2)};
    }
}

int solve()
{
    sort(map, map + N, comp1);
    if (calc_day(12, 1) > map[0].e)
    {
        return 0;
    }
    sort(map, map + N, comp2);
    if (calc_day(3, 1) < map[0].s)
    {
        return 0;
    }

    int idx = 0;
    for (int i = 1; i < N; i++)
    {
        flower now = map[i];
        if (now.s <= calc_day(3, 1))
        {
            if (now.e > map[idx].e)
                idx = i;
        }
    }

    while (1)
    {
        if (map[idx].e > calc_day(11, 30))
            break;

        flower now = {1, 1};
        int temp = 0;
        for (int i = idx + 1; i < N; i++)
        {
            flower next = map[i];
            if (next.s <= map[idx].e)
            {
                if (next.e > now.e)
                {
                    now = next;
                    temp = i;
                }
            }
        }

        idx = temp;

        if (now.s == 1)
        {
            return 0;
        }
        else
            ans++;
    }
    return ans;
}
int main()
{
    // freopen("../input.txt", "r", stdin);

    InputData(); // 입력받는 부분

    int sol = solve();

    cout << sol << endl; // 출력하는 부분
    return 0;
}