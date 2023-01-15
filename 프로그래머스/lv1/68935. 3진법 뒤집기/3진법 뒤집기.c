#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int n) {
    int answer = 0;
    int arr[100000000];
    int idx=0;
    while(n)
    {
        int t = n%3;
        arr[idx++] = t;
        n/=3;
    }
    for(int i=0;i<idx;i++)
    {
        answer += (arr[i]*pow(3,idx-i-1));
    }
    return answer;
}