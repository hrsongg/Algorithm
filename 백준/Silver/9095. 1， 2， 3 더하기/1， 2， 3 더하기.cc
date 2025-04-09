// 9095 1, 2, 3 더하기
#include <bits/stdc++.h>
using namespace std;
int T;
int dp[12];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i=4; i<=10; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        
    int inp;
    while(T--){
        cin >> inp;
        cout << dp[inp] << "\n";
    }

    return 0;
}