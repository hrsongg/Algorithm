 // BOJ 1021 회전하는 큐
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, x; 
    int ans = 0;
    deque<int> dq;
    cin >> n >> m;
    for(int i=1; i<=n; i++) dq.push_back(i);

    while(m--){
        cin >> x;
        int idx = find(dq.begin(), dq.end(), x) - dq.begin(); // x의 인덱스 
        while(dq.front() != x){
            if(idx < dq.size() - idx){ // 왼쪽에 있으면 
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{// 오른쪽에 있으면 
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans++;
        }
        dq.pop_front(); // x값을 처리했으면 
    }
    cout << ans;
    return 0;
}