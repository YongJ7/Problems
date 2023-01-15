#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int A[1000001];
int B[1000001];
int v[2000002];
int N, M;
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
		v[i] = A[i];
	}
	for (int i = 0;i < M;i++) {
		cin >> B[i];
		v[N + i] = B[i];
	}
	sort(v, v + (M + N));

	for (int i = 0;i < M + N;i++) {
		cout << v[i] << " ";
	}
	return 0;
}