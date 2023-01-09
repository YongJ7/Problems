#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef pair<int, int>P;
int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,1,0,-1,0 };
P arr[101][101];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b; cin >> a >> b;
	int n, m; cin >> n >> m;
	vector<P>robot(1, { 0,0 });
	for (int i = 1; i <= n; i++) {
		int x, y; char d;
		cin >> x >> y >> d;
		int dir = 0;
		if (d == 'N') dir = 1;
		else if (d == 'E') dir = 2;
		else if (d == 'S') dir = 3;
		else if (d == 'W') dir = 4;
		arr[x][y].first = i;
		arr[x][y].second = dir;
		robot.push_back({ x,y });
	}
	for (int i = 0; i < m; i++) {
		int num, cnt; char order;
		cin >> num >> order >> cnt;

		int x = robot[num].first;
		int y = robot[num].second;
		int dir = arr[x][y].second;

		if (order == 'F') {
			arr[x][y].first = 0;
			arr[x][y].second = 0;
			for (int j = 0; j < cnt; j++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx <= 0 || nx > a || ny <= 0 || ny > b) {
					cout << "Robot "<< num <<" crashes into the wall";
					return 0;
				}
				if (arr[nx][ny].first != 0) {
					cout << "Robot " << num << " crashes into robot " << arr[nx][ny].first;
					return 0;
				}
				x = nx; y = ny;
			}
			arr[x][y].first = num;
			arr[x][y].second = dir;
			robot[num].first = x;
			robot[num].second = y;
		}
		else if (order == 'R') {
			while (cnt--) {
				arr[x][y].second += 1;
				if (arr[x][y].second > 4)
					arr[x][y].second = 1;
			}
		}
		else if (order == 'L') {
			while (cnt--) {
				arr[x][y].second -= 1;
				if (arr[x][y].second < 1)
					arr[x][y].second = 4;
			}
		}
	}
	cout << "OK";
	return 0;
}