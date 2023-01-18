#include <string>
#include <vector>

using namespace std;
int vect[1000001];
int solution(int n) {
    int cnt=0;
    for(int i=2;i<=n;i++) vect[i]=i;
    for(int i=2;i<=n;i++){
        if(vect[i]==i) cnt++;
        for(int j=i+i;j<=n;j+=i) vect[j]=0;
    }
    return cnt;
}