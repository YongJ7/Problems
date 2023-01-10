#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> map(n, 1);
    for (int i = 0; i < lost.size(); i++) {
        map[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        map[reserve[i] - 1]++;
    }
    for (int i = 0; i < map.size(); i++) {
        if (map[i] == 0) {
            if (i != 0 && map[i - 1] == 2) {
                map[i - 1]--;
                map[i]++;
            }
            else if (i != map.size() - 1 && map[i + 1] == 2) {
                map[i + 1]--;
                map[i]++;
            }
        }
    }
    for (int i = 0; i < map.size(); i++) {
        if (map[i] !=0) {
            answer++;
        }
    }
    return answer;
}