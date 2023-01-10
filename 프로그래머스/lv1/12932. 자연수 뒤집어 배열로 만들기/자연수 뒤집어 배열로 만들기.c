#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(sizeof(int)*12);
    char s[100];
    sprintf(s,"%lld",n);
    int a=0;
    for(int i=strlen(s)-1;i>=0;i--){
        answer[a++]=s[i]-'0';
    }
    return answer;
}