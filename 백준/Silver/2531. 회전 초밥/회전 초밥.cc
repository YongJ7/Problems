#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, D, K, C; // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
int arr[30001]; // 회전 초밥 테이블
bool check[30001];

void Input()
{
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

int solve()
{
    int sol = 0;

    for (int i = 0; i < N; i++)
    {
        int flag = 0;
        int coupon = 1;
        for (int j = i; j < i + K; j++)
        {
            if (!check[arr[j % N]])
                check[arr[j % N]] = true;
            else
                flag++;
            if (arr[j % N] == C)
                coupon = 0;
        }

        sol = max(sol, K - flag + coupon);
        memset(check, false, sizeof(check));
    }
    return sol;
}
int main()
{
    // freopen("../input.txt", "r", stdin);
    Input();

    int ans = solve();

    cout << ans << endl;
    return 0;
}