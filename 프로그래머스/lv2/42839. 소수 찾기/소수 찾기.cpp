#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
bool issosu(int n)
{
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    vector<char> a;
    vector<int> n;
    for(int i=0;i<numbers.size();i++){
        a.push_back(numbers[i]);
    }
    sort(a.begin(),a.end());
    do{
        string t="";
        for(int i=0;i<a.size();i++){
            t.push_back(a[i]);
            n.push_back(stoi(t));
        }
    }while(next_permutation(a.begin(),a.end()));
    sort(n.begin(),n.end());
    n.erase(unique(n.begin(),n.end()),n.end());
    
    for(int i=0;i<n.size();i++){
        if(issosu(n[i])) answer++;
    }
    return answer;
}