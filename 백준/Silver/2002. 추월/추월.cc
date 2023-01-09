#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> arr;
vector<string> v;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N, cnt = 0;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.insert({ s,i });
	}
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[v[i]] > arr[v[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}