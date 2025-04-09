// 11286 절댓값 힙
#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        // 절대값이 같다면, 두 수가 다르고 앞이 양수, 뒤가 음수일 때에만 true
        // 두 수가 같으면 false여야 하므로 
        return a>0 && b<0;
    }
};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        if(x == 0){
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}