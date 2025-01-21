// BOJ 5397 키로거
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    string password;

    while(t--){
        list<char> li;
        list<char>::iterator cursor = li.begin();
        cin >> password;
        for(auto a: password){
            if(a == '<'){
                if(cursor != li.begin())
                cursor--;
            }
            else if(a == '>'){
                if(cursor != li.end())
                cursor++;
            }
            else if(a == '-'){
                if(cursor != li.begin()){
                    cursor--;
                    cursor = li.erase(cursor);
                }
            }
            else{ // 비밀번호의 일부 
                li.insert(cursor, a);
            }
        }
        for(auto x: li) cout << x;
        cout << "\n";

    }

    return 0;
}
