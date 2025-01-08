#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer(strings.begin(), strings.end());
    sort(answer.begin(), answer.end(), [&](const auto& a, const auto& b){
        if(a[n] == b[n]){ // i번째 문자열이 같으면
            return a < b; // 사전순 정렬
        }
        // i번째 문자열 우선 정렬
        return a[n] < b[n];
    });
    
    
    return answer;
}