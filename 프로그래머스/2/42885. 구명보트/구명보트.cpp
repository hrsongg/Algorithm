#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    sort(people.begin(), people.end()); // 오름차순 정렬 
    for(auto p: people){
        dq.push_back(p);
    }
    while(!dq.empty()){
        if(dq.size() >= 2 && (dq.front() + dq.back() <= limit)){ // 2명 구출
            dq.pop_back(); dq.pop_front();
        }
        else if(dq.front() < dq.back()){ // 1명 구출
            dq.pop_back();
        }
        else{ // 1명 구출
            dq.pop_front();
        }
        answer++; 
    }
    
    return answer;
}