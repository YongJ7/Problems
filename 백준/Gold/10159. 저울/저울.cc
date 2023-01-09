#include <iostream>

using namespace std;

int N,M;
int arr[101][101];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0); 

    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a,b; cin>>a>>b;
        arr[a][b] = 1; // a가 더 크기 때문에 1
        arr[b][a] = -1; // 반대는 -1
    }
    //플로이드 와샬 알고리즘
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                // 비교하는 값들이 0이 아닌 같은 값일 때 초기화
                if(arr[i][k] == arr[k][j] && arr[i][k] != 0) arr[i][j] = arr[i][k];
            }
        }
    }
    // i,j 비교할 때 0이 아닌 경우 비교 불가
    for(int i=1;i<=N;i++)
    {
        int cnt = N-1;
        for(int j=1;j<=N;j++)
        {
            if(arr[i][j]!=0) cnt--;
        }
        cout<<cnt<<'\n';
    }
}