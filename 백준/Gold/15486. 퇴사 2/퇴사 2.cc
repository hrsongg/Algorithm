// 15486 퇴사2
#include <bits/stdc++.h>
using namespace std;
int N;
int t[1500004];
int p[1500004];
int d[1500004];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> t[i] >> p[i];
    
    for(int i=N; i>=1; i--){
        if(i+t[i] <= N+1){
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        else d[i] = d[i+1];
    }
    cout << *max_element(d, d+N+1);
}