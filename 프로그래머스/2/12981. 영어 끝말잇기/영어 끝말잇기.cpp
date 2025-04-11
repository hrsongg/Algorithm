#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> st; // 중복되는 단어 체크하기 위한 집합 
    int ans = -1 ; // 정답 인덱스 
    int wsize = words.size();
    string prev = words[0]; // 이전 단어
    string nxt; // 새로 확인할 단어
    st.insert(words[0]); 
    for(int i=1; i<wsize; i++){
        nxt = words[i];
        int prev_size = prev.size();
        if(prev[prev_size-1] != nxt[0]){ // 앞 사람이 말한 단어의 문자로 시작하는 단어가 아니면
            ans = i; // ans 갱신
            break;
        }
        if(st.count(nxt)) { // 이전에 등장했던 단어를 사용하면 
            ans = i; // ans 갱신
            break; // 이전에 등장했던 단어는 사용할 수 없습니다. 
        }
        st.insert(nxt);
        prev = nxt; // 갱신
    }
    
    cout << ans;
    if(ans == -1) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back((ans % n) +1);
        answer.push_back(ans / n + 1);
    }
    return answer;
}