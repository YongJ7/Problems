#include <iostream>
using namespace std;
int map[4000001];
int N, p;
bool arr[4000001];
int all[4000001];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;

    for (int i = 2;i <= N;i++) {
        if (!arr[i]) {
            for (int j = i * 2;j <= N;j += i) {
                arr[j] = 1;
            }
            all[i] = i;
        }
    }
    int a = 0;
    for (int i = 0;i <= N;i++) {
        if (all[i] != 0) {
            map[a] = all[i];
            a++;
            p++;
        }
    }

    int sum = map[0];
    int h = 0, t = 0;
    int cnt = 0;
    while (h <= t && t < p) {
        if (sum < N) {
            t++;
            sum += map[t];
        }
        if (sum == N) {
            cnt++;
            t++;
            sum += map[t];
        }
        if (sum > N) {
            sum -= map[h];
            h++;
        }
    }
    cout << cnt << '\n';
    return 0;
}
