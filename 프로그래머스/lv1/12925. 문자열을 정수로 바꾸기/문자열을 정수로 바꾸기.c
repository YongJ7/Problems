#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char arr[5];
    if(s[0]=='-'){
        int l =strlen(s);
        for(int i=1;i<l;i++){
            arr[i-1]=s[i];
        }
        answer = atoi(arr);
        answer = -answer;
    }
    if(s[0]=='+'){
        int l =strlen(s);
        for(int i=1;i<l;i++){
            arr[i-1]=s[i];
        }
        answer = atoi(arr);
    }
    else{
        int l =strlen(s);
        for(int i=0;i<l;i++){
            arr[i]=s[i];
        }
        answer = atoi(arr);
    }
    
    return answer;
}