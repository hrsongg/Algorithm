// 1463 1로 만들기
#include <bits/stdc++.h>
using namespace std;

int N; // ~10^6
int dp[1000002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[1] = 0; 
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1]+1;
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout << dp[N];

    return 0;
}