#include <bits/stdc++.h>
#define MAX 5000001
using namespace std;

bool prime_num[MAX];
bool used[MAX];
long long point_DW, point_GS;
priority_queue<int> DW,GS;

void Eratosthenes()
{
    for(int i=2;i<MAX;i++)
    {
        prime_num[i] = true;
    }
    for(int i=2;i<=sqrt(MAX);i++)
    {
        if(prime_num[i] == false) continue;
        for(int j=i+i;j<MAX;j+=i)
        {
            prime_num[j] = false;
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    Eratosthenes();

    int N; cin>>N;
    
    for(int i=0;i<N;i++)
    {
        int D,G; cin>>D>>G;

        if(prime_num[D] == false){
            if(GS.size()>=3){
                int a = GS.top();
                GS.pop();
                int b = GS.top();
                GS.pop();
                point_GS += GS.top();
                GS.push(a);
                GS.push(b);
            }
            else{
                point_GS += 1000;
            }
        }
        else{
            if(used[D]){
                point_DW -= 1000;
            }
            else{
                DW.push(D);
                used[D] = true;
            }
        }
        
        if(prime_num[G] == false){
            if(DW.size()>=3){
                int a = DW.top();
                DW.pop();
                int b = DW.top();
                DW.pop();
                point_DW += DW.top();
                DW.push(a);
                DW.push(b);
            }
            else{
                point_DW += 1000;
            }
        }
        else{
            if(used[G]){
                point_GS -= 1000;
            }
            else{
                GS.push(G);
                used[G] = true;
            }
        }
    }
    if(point_DW > point_GS) cout<<"소수의 신 갓대웅\n";
    else if(point_DW < point_GS) cout<<"소수 마스터 갓규성\n";
    else cout<<"우열을 가릴 수 없음\n";
}