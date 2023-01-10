#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> arr;
    
    for(vector<string> pair : clothes)
        arr[pair[1]]++;
    
    for(auto it = arr.begin(); it != arr.end() ; it++){
        answer = answer*(it->second +1 );
    }
    
    return answer-1;
}