#include <bits/stdc++.h>

using namespace std;
int cur = 0;
// 최소 필요 피로도: 해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도
// 소모 피로도: 던전을 탐험한 후 소모되는 피로도

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0; // 유저가 탐험할 수 있는 최대 던전 수 - 최대 값만 선택
    int dsize = dungeons.size(); // 던전의 총 개수 
    cur = k; // 현재 피로도 
    
    vector<int> v; // permutation에 사용할 배열 (idx 저장)
    for(int i=0; i<dsize; i++){ 
        v.push_back(i);
    }
    
    do{
        int cnt = 0; // 해당 permutation에서 가능한 값
        cur = k; // cur값 초기화
        for(int num: v){
            int minimum = dungeons[num][0]; // 최소 필요 피로도
            int consume = dungeons[num][1]; // 소모 피로도
            if(cur >= minimum){
                cur -= consume;
                cnt++;
            }
        }
        answer = max(answer, cnt); // 가장 최대 값만 선택

    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}