#include <bits/stdc++.h>

using namespace std;

int dp[60002];

int solution(int n) {
    int answer = 0;
    
    dp[1] = 1; dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) % 1000000007;
    }
    answer = dp[n];
    return answer;
}