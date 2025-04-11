#include <bits/stdc++.h>

using namespace std;
//자신이 원하는 제품과 수량이 할인하는 날짜와 10일 연속으로 일치할 경우에 맞춰서 회원가입
//["banana", "apple", "rice", "pork", "pot"]
//[3, 2, 2, 2, 1]
//["chicken", "apple", "apple", "banana", "rice", 
// "apple", "pork", "banana", "pork", "rice", 
// "pot", "banana", "apple", "banana"]

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int nsize = want.size(); // want의 길이 
    int dsize = discount.size(); // discount의 길이 
    vector<string> ws; // 계속 쓸 배열
    // ws 벡터 초기화 
    for(int i=0; i<nsize; i++){
        int cnt = number[i]; // 해당 원소가 몇 개인지 
        for(int j=0; j<cnt; j++){
            ws.push_back(want[i]);
        }
    }
    
    for(int i=0; i<(dsize-9); i++){ // 총 dsize - 10번 체크 
        multiset<string> ms(discount.begin()+i, discount.begin()+i+10); // 해당 i일로부터 10일간 할인받을 목록
        for(int idx = 0; idx < ws.size(); idx++){
            if(ms.count(ws[idx]) >= 1) ms.erase(ms.find(ws[idx]));
            else break;
        }
        if(ms.size()==0) answer++;
    }
    return answer;
}