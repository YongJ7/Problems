#include <string>
#include <vector>

using namespace std;

int ans,cnt;

string to_binary(int num) {
	string str = "";
	while (num > 0) {
		if (num % 2 == 1) str = "1" + str;
		else str = "0" + str;
		num >>= 1;
	}
	return str;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    while(1)
    {    
        cnt++;
        int l = s.size();
        
        int num = 0;
    
        for(int i=0;i<l;i++)
        {
            if(s[i]=='1') {
                num++;
            }
        }
    
        ans += (l - num);
        if(num == 1) break;
        s = to_binary(num);
    }
    answer.push_back(cnt);
    answer.push_back(ans);
    return answer;
}