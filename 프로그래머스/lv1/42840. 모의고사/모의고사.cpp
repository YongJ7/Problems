#include <string>
#include <vector>
#include <iostream>

using namespace std;
int su1[10001];
int su2[10001];
int su3[10001];
int su11[5]={1,2,3,4,5};
int su22[8]={2,1,2,3,2,4,2,5};
int su33[10]={3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    int cn1=0,cn2=0,cn3=0;
    for(int i =0;i<answers.size();i++){
        if(su11[i%5]==answers[i]) cn1++;
        if(su22[i%8]==answers[i]) cn2++;
        if(su33[i%10]==answers[i]) cn3++;
    }
    vector<int> answer;

    int a =max(max(cn1,cn2),cn3);
    if(cn1==a) answer.push_back(1);
    if(cn2==a) answer.push_back(2);
    if(cn3==a) answer.push_back(3);
    return answer;
}