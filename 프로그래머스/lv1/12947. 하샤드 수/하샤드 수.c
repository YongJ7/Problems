#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    char s[100];
    int a=0;
    sprintf(s,"%d",x);
    int sum=0;
    for(int i=0;i<strlen(s);i++){
        sum+=s[i]-'0';
    }
    if(x%sum!=0) answer=false;
    return answer;
}