// 11055 가장 큰 증가하는 부분 수열 (답지)
#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1002];
int dp[1002]; // 해당 위치에서 뒤에까지 남은 원소 중 가장 큰 증가하는 부분수열 합

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        dp[i] = arr[i]; // 해당 위치의 배열 값으로 초기화
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }
    int ret = *max_element(dp, dp+N);
    cout << ret;
}