#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    if(a>b){
        int t =a;
        a=b;
        b=t;
    }
    for(int i=a;i<=b;i++){
        answer+=i;
    }
    if(a==b) answer = a;
    return answer;
}