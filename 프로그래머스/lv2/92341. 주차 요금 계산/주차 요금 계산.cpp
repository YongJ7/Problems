#include <string>
#include <vector>

using namespace std;
int Car_time[10000];
pair<bool,int> Car_map[10000];
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(auto rec : records)
    {
        string h = rec.substr(0,2);
        string m = rec.substr(3,2);
        string num = rec.substr(6,4);
        int now_time = stoi(h)*60 + stoi(m);
        int car_num = stoi(num);
        if(rec[11] == 'I'){
            Car_map[car_num].first = true;
            Car_map[car_num].second = now_time; 
        }
        else{
            Car_map[car_num].first = false;
            Car_time[car_num] += (now_time - Car_map[car_num].second);
        }
    }
    for(int i=0;i<10000;i++)
    {
        if(Car_map[i].first){
            Car_map[i].first = false;
            Car_time[i] += ((23*60+59)-Car_map[i].second);
        }
    }
    for(int i=0;i<10000;i++)
    {
        int tot_fee = 0;
        int tot_time = Car_time[i];
        if(tot_time>fees[0])
        {
            tot_time -= fees[0];
            if(tot_time % fees[2] != 0) tot_fee += fees[3];
            tot_fee += (tot_time/fees[2])*fees[3];
        }
        tot_fee += fees[1];
        if (tot_time) answer.push_back(tot_fee);
    }
    return answer;
}