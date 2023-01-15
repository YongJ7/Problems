#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*strlen(s)+1);
    int a=0;
    answer[strlen(s)]='\0';
    for(int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            answer[i]=s[i];
            a=0;
            continue;
        }
        if(a%2==0){
            if(s[i]>='a'&&s[i]<='z'){
                answer[i]=s[i]-32;
            }
            else{
                answer[i] =s[i];
            }
        }
        else{
            if(s[i]>='A'&&s[i]<='Z'){
                answer[i]=s[i]+32;
            }
            else{
                answer[i] =s[i];
            }
        }
        a++;
    }
    return answer;
}