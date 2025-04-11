#include <bits/stdc++.h>

using namespace std;
bool visited[52]; // 방문 여부 체크 
int answer = 50; // maximum

bool check(string a, string b){ // 두 단어가 한 문자만 다른지 확인하는 함수
    // 모든 단어의 길이는 같음
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt > 1) return false; 
    else return true; // 한 문자만 다를 경우 
}

void dfs(int dep, string st, string tgt, vector<string>& words){
    if(st == tgt){
        answer = min(answer, dep);
        return;
    }
    for(int i=0; i<words.size(); i++){
        if(check(st, words[i]) && !visited[i]){ // 단어 하나 차이나는데 아직 방문하지 않았다면
            visited[i] = true; // 방문 처리
            dfs(dep+1, words[i], tgt, words);
            visited[i] = false; // 방문 해제 
        }
    }
    
}


int solution(string begin, string target, vector<string> words) {
    //int answer = 0;
    dfs(0, begin, target, words);
    if(answer == 50) return 0;
    
    return answer;
}