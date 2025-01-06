#include <bits/stdc++.h>

using namespace std;

int convert(string s){
    string mm = s.substr(0, 2);
    string ss = s.substr(3, 2);
    int min = stoi(mm);
    int sec = stoi(ss);
    
    return min*60 + sec;
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 분으로 전환
    int video_max = convert(video_len); 
    int now = convert(pos);
    int st = convert(op_start);
    int en = convert(op_end);
    
    for(auto cmd: commands){
        if(st <= now && now <= en){
            now = en;
        }
        if(cmd == "prev"){
           if(now < 10) {
               now = 0;
           }
            else{
                now -= 10;
            }
        }else{ // cmd == "next"
            if((video_max - now) < 10){
                now = video_max;
            }
            else{
                now += 10;
            }
        }
    }
    if(st <= now && now <= en){
        now = en;
    }
    // 출력 계산
    int m = now / 60;
    int s = now % 60;
    string minuteStr = (m < 10 ? "0" : "") + to_string(m); // 두 자리로 만들기
    string secondStr = (s < 10 ? "0" : "") + to_string(s); // 두 자리로 만들기
    answer = minuteStr + ":" + secondStr;
    
    return answer;
}