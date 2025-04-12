#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[2002];

ll solution(int n) {
    //ll answer = 0;
    dp[1] = 1, dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    return dp[n];
}