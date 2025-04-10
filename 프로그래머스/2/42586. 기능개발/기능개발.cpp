#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> res; // N일 간 작업 후 배포 가능
    for(int i=0; i<progresses.size(); i++){
        int prg = progresses[i];
        int spd = speeds[i];
        int diff = 100-prg; // 남은 %수 
        if(diff % spd == 0){
            res.push_back(diff/spd); 
        }else{
            res.push_back(diff/spd + 1);
        }
    }
    stack<int> st; int cnt = 1;
    st.push(res[0]);
    if(res.size() > 1){
        for(int i=1; i<res.size(); i++){
            if(st.top() < res[i]){
                st.push(res[i]);
                answer.push_back(cnt); 
                cnt = 1; // cnt 초기화 
            }
            else{
                cnt++; 
            }
        }
    }
    answer.push_back(cnt); // 마지막 원소 추가 
    
    return answer;
}