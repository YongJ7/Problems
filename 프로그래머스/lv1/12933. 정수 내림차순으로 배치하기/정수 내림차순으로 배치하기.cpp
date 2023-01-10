#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string v=to_string(n);
    sort(v.begin(),v.end(),greater<>());
    answer=stoll(v);
    return answer;
}