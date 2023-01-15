#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;
    
    while(true){
        getline(cin, s);
        if(s=="")return 0;
        cout<<s<<"\n";
    }
    return 0;
}