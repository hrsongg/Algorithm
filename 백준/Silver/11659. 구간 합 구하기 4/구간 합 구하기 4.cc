// 11659 구간 합 구하기 4
#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[100002];
int dp[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for(int i=2; i<=N; i++) {
        dp[i] = arr[i] + dp[i-1];
    }
    int st, en;
    for(int i=0; i<M; i++){
        cin >> st >> en;
        cout << dp[en] - dp[st-1] << "\n";
    }
    return 0;
}