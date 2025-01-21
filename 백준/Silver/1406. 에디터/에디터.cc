// BOJ 1406 에디터 
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    list<char> li;
    list<char>::iterator cur = li.end(); // 커서 
    string s; int m; 
    char cmd, ch;
    cin >> s;
    for(auto alp: s) li.push_back(alp);
    cin >> m;

    for(int i=0; i<m; i++){
        cin >> cmd;
        if(cmd == 'L'){ // 커서를 왼쪽으로 한 칸 옮김(커서가 문장의 맨앞이면 무시)
            if(cur != li.begin()) cur--;
        }
        else if(cmd == 'D'){ // 커서를 오른쪽으로 한 칸 옮김(커서가 문장의 맨 뒤이면 무시됨)
            if(cur != li.end()) cur++;
        }
        else if(cmd == 'B'){ // 커서 왼쪽에 있는 문자를 삭제(커서가 문장의 맨 앞이면 무시됨)
            if(cur != li.begin()) {
                cur--;
                cur = li.erase(cur); 
            }
        }
        else if(cmd == 'P'){ // ch를 커서 왼쪽에 추가
            cin >> ch;
            li.insert(cur, ch);
        }
    }
    
    // 편집기에 입력되어 있는 문자열을 출력
    for(auto it = li.begin(); it != li.end(); it++){
        cout << *it;
    }

    return 0;
}
