#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, double> arr;
string fam_tree[51][3];

int N, M;
string king, s, ans;
double mm;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M >> king;
	arr[king] = 1.0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(i == 0) cin >> fam_tree[j][0] >> fam_tree[j][1] >> fam_tree[j][2];
			arr[fam_tree[j][0]] = (arr[fam_tree[j][2]] + arr[fam_tree[j][1]]) / 2;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if (arr.find(s) != arr.end() && arr[s] > mm)
		{
			ans = s;
			mm = arr[s];
		}
	}

	cout << ans;
}