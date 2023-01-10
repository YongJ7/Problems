#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int F[100001];
    F[0]=1, F[1]=1;
    for(int i =2;i<=n;i++){
        F[i]=(F[i-2]+F[i-1])%1234567;
    }
    return F[n-1];
}