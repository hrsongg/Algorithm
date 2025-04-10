#include <bits/stdc++.h>
using namespace std;
int dp[100002][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    for(int i=0; i<4; i++){ // dp배열 초기화 
        dp[0][i] = land[0][i];
    } 
    for(int i=1; i<N; i++){ // 점화식 
        dp[i][0] = land[i][0] + max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3]));
        dp[i][1] = land[i][1] + max(dp[i-1][0], max(dp[i-1][2], dp[i-1][3]));
        dp[i][2] = land[i][2] + max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3]));
        dp[i][3] = land[i][3] + max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
    }
    
    answer = max(dp[N-1][0], max(dp[N-1][1], max(dp[N-1][2], dp[N-1][3])));
    return answer;
}