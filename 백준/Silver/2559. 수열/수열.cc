#include <iostream>
using namespace std;

int map[100001];
int N, K;
int maxi;
int sum;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> map[i];
	}
	for (int i = 0;i < K;i++) {
		sum += map[i];
	}
	maxi = sum;

	for (int i = 0;i < N - K;i++) {
		sum -= map[i];
		sum += map[i + K];
		if (sum > maxi) maxi = sum;
	}
	
	cout << maxi;
	return 0;
}