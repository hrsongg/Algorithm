// 7785 회사에 있는 사람 
#include <bits/stdc++.h>
using namespace std;

int N; 
string name, sts;
set <string> us;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        cin >> name >> sts;
        if(sts == "enter"){ // enter
            us.insert(name);
        }else{ // leave
            us.erase(name);
        }
    }

    // 사전 순의 역순으로 출력 
    stack<string> st;
    for(auto s: us){
        st.push(s);
    }
    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }
    return 0;
}

