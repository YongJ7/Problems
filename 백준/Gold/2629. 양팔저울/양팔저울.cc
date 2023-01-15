#include <bits/stdc++.h>
using namespace std;
int N, n;
bool D[31][40001];
int A[31];

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> n;
    D[0][0] = 1;

    for (int i=0;i<N;i++){
        for (int j=0;j<40001;j++) if (D[i][j]){
            D[i+1][j] = true;
            D[i+1][j+A[i+1]] = true;
            D[i+1][abs(j-A[i+1])] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        if (D[N][x])
        {
            printf("%c ", 'Y');
        }
        else
        {
            printf("%c ", 'N');
        }
    }
    return 0;
}