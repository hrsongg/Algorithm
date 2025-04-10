#include <bits/stdc++.h>

using namespace std;
vector<string> dic; // 사전 모음, 중복순열
char alp[5] = {'A', 'E', 'I', 'O', 'U'};
char arr[5]; // 중복순열 수 저장 배열 

void func(int k, int m){
    if(k == m){
        string s = "";
        for(int i=0; i<m; i++){
            s += arr[i];
        }
        dic.push_back(s);
        return;
    }
    for(int i=0; i<5; i++){
        arr[k] = alp[i];
        func(k+1, m);
    }
}

int solution(string word) {
    int answer = 0;
    
    for(int i=1; i<=5; i++) {
        func(0, i); // 사전 만들기
    }
    sort(dic.begin(), dic.end()); // 정렬 
    for(int i = 0; i<dic.size(); i++){
        if(dic[i] == word){
            return i+1;
        }
    }
    return answer;
}