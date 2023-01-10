#include <string>
#include <vector>

using namespace std;
int gcd(int a,int b)
{
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int g=0;
    if(n>m) g = gcd(n,m);
    else g = gcd(m,n);
    int l =n*m/g;
    answer.push_back(g);
    answer.push_back(l);
    
    return answer;
}