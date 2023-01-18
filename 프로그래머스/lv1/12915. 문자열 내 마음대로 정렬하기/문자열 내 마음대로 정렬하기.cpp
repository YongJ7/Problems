#include <bits/stdc++.h>
using namespace std;
int ind;
bool compare(string a,string b){
    if(a[ind]<b[ind]) return true;
    if(a[ind]==b[ind]) return a<b;
    return false;
}
vector<string> solution(vector<string> strings, int n) {
    ind = n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}