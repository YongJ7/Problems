#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long int sum =0;
    for(int i=1;i<=count;i++){
        sum+=price*i;
    }
    answer = sum-money;
    if(answer<0) answer =0;
    return answer;
}