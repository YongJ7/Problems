#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
int A[MAXN];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	sort(A+1, A+N+1);
	int a = 1, b = 2;
	for (int l=1,r=N;l<r;l++){
		while (l < r-1 && A[l]+A[r] > 0) r--;
		if (abs(A[a]+A[b]) > abs(A[l]+A[r]))
			a = l, b = r;
		if (r+1 <= N && abs(A[a]+A[b]) > abs(A[l]+A[r+1]))
			a = l, b = r+1;
	}
	printf("%d %d\n", A[a], A[b]);
}