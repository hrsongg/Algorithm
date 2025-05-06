// 11053 가장 긴 증가하는 부분 수열
#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1004];
int dp[1004];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
            dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans = *max_element(dp, dp+N);
    cout << ans+1;
}