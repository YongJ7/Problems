#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool find(int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0) cnt++;
    }
    if(cnt%2==0) return true;
    else return false;
}
int solution(int left, int right) {
    int answer = 0;
    for(int i=left;i<=right;i++)
    {
        if(find(i)) answer+=i;
        else answer-=i;
    }
    return answer;
}