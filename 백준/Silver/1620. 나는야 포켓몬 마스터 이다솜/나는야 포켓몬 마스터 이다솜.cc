// 1620 나는야 포켓몬 마스터 이다솜
#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_map<string, int> um;
vector<string> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int num = 0;
    string name, ques;
    v.push_back("-");
    while(N--){
        num++;
        cin >> name;
        um[name] = num;
        v.push_back(name);
    }
    while(M--){
        cin >> ques;
        if(isdigit(ques[0])){ // 숫자이면
            int i = stoi(ques);
            cout << v[i] << "\n";
        }
        else{ // 문자이면
            cout << um[ques] << "\n"; 
        }
    }

    return 0;
}