// 15988 1, 2, 3 더하기 3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, num;
ll dp[1000004];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i=4; i<=1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }
    
    while(T--){
        cin >> num;
        cout << dp[num] << "\n";
    }
}