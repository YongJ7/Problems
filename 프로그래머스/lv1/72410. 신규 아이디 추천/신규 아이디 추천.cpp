#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    // 1단계
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z') new_id[i]+=32;
    }
    // 2단계
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='a'&&new_id[i]<='z') continue;
        if(new_id[i]>='0'&&new_id[i]<='9') continue;
        if(new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.') continue;
        else {
            new_id.erase(i,1);
            i--;
        }
    }
    //3 단계
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]=='.'&&new_id[i+1]=='.'){ new_id.erase(i+1,1);i--;}
    }
    //4 단계
    while(new_id[0]=='.'){
        new_id.erase(0,1);
    }
    while(new_id[new_id.size()-1]=='.'){
        new_id.erase(new_id.size()-1);
    }
    //5 단계
    if(new_id.empty()) new_id+="a";
    // 6단계
    if(new_id.size()>=16) new_id.erase(15);
    if(new_id[14]=='.') new_id.erase(14);
    // 7단계
    while(new_id.size()<3) new_id+=new_id[new_id.size()-1];
    return new_id;
}