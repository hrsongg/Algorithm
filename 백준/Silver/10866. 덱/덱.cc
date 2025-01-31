 // BOJ 10866 덱
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t, x; 
    string cmd; 
    deque<int> dq;
    
    cin >> t;
    while(t--){
        cin >> cmd;
        if(cmd == "push_back"){
            cin >> x;
            dq.push_back(x);
        }
        else if(cmd == "push_front"){
            cin >> x;
            dq.push_front(x);
        }
        else if(cmd == "pop_front"){
            if(dq.size()){
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else{ cout << -1 << "\n";}
        }
        else if(cmd == "pop_back"){
            if(dq.size()){
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else{ cout << -1 << "\n";}
        }
        else if(cmd == "size"){
            cout << dq.size() << "\n";
        }
        else if(cmd == "empty"){
            if(dq.size()) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
        else if(cmd == "front"){
            if(dq.size()){
                cout << dq.front() << "\n";
            }
            else{ cout << -1 << "\n";}
        }
        else if(cmd == "back"){
            if(dq.size()){
                cout << dq.back() << "\n";
            }
            else{ cout << -1 << "\n";}
        }
    }

    return 0;
}