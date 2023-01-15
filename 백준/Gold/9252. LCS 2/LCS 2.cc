#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[1001][1001];
int main() {
	string a, b; cin >> a >> b;
	for(int i=1; i<=b.size(); i++)
		for (int j = 1; j <= a.size(); j++) {
			if (a[j - 1] == b[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	int k = a.size();
	string kk;
    
	for (int i = b.size(); i >= 0; i--) {
		if (dp[i][k] == 0)
			break;
		for (int j = k; j >= 0; j--) {
			if (dp[i][j] == dp[i - 1][j])
				break;
			if (dp[i][j] != dp[i][j - 1]) {
				kk += a[j-1];
				k = j - 1;
				break;
			}
		}
	}
	cout << dp[b.size()][a.size()] << '\n';;
	if (dp[b.size()][a.size()] == 0)
		return 0;
	for (int i = kk.size() - 1; i >= 0; i--)
		cout << kk[i];
	cout << '\n';
}