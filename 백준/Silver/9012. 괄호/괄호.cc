#include <iostream>
#include <string>
using namespace std;
string v[100];
int main()
{
	int n;
	cin >> n;
	
	for (int x = 0;x < n;x++) {
		cin >> v[x];
	}
	for (int i = 0;i < n;i++) {
		int cnt = 0;
		int l = v[i].size();
		for (int x = 0;x < l;x++) {
			if (v[i][x] == '(')cnt++;
			else if (v[i][x] == ')')cnt--;
			if (cnt < 0) {
				break;
			}
		}
		if (cnt == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}