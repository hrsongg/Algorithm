#include <bits/stdc++.h>
using namespace std;
set<int> t_type; // 토핑이 총 몇 가지 종류인지 저장하는 집합
int t_size; // 토핑이 총 몇 가지 종류인지 개수 
int N; // 토핑이 총 몇 개인지 
set<int> young; // 동생 집합
set<int> old; // 형 집합 
int young_arr[10002]; // young에 몇 개가 들어있는지 확인 

int solution(vector<int> topping) {  
    int answer = 0;
    N = topping.size(); // 1,000,000
    for(auto t: topping){
        t_type.insert(t);
    }
    t_size = t_type.size();
    // set 초기화 
    young.insert(topping[0]);
    for(int i=1; i<N; i++){
        old.insert(topping[i]);
        young_arr[topping[i]] += 1;
    }
    if(young.size() == old.size()) answer++;
    
    // N-2번 더 확인해야 함
    if(N >= 2){
        for(int i=1; i<N-1; i++){
            young.insert(topping[i]);
            // old erase는 이전에 몇 개 있는지 확인하고 지워야함
            if(old.count(topping[i])){ // 존재 한다면
                if(young_arr[topping[i]] > 1) { // 2개 이상 존재한다면
                    young_arr[topping[i]] -= 1;
                }
                else{ // 1개만 존재한다면
                    old.erase(topping[i]); // 지워도 됨
                    young_arr[topping[i]] = 0;
                }
            }
            if(young.size() == old.size()) answer++;
        }
    }

    
    // for(int i=1; i<N; i++){ // 총 N-1가지 경우가 존재 1 ~ N-1
    //     // 동생 0 ~ i-1
    //     young.clear(); old.clear(); // 매 경우의 수마다 집합 초기화 
    //     for(int j=0; j<i; j++){
    //         young.insert(topping[j]);
    //     }
    //     // 형 i ~ N-1
    //     for(int j=i; j<N; j++){
    //         old.insert(topping[j]);
    //     }
    //     if(young.size() == old.size()) answer++;
    // }
    
    return answer;
}