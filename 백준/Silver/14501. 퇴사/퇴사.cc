// 14501 퇴사 (답지봄)
#include <bits/stdc++.h>
using namespace std;
int N;
int t[20];
int p[20];
int d[20]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i=1; i<=N; i++) cin >> t[i] >> p[i];

    for(int i=N; i>=1; i--){
        // i번째 일에 상담을 할 수 있을 경우
        if(i + t[i] <= N+1){
            // {i번째 일에 상담을 했을 때, 상담을 하지 않았을 때}의 경우 중 최대 수익을 취함
            d[i] = max(d[i+t[i]] + p[i], d[i+1]);
        }
        else d[i] = d[i+1];
    }
    cout << *max_element(d, d+N+1);
}
