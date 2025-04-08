// 11652 카드
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int N; 
long long a[100005];


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    sort(a, a+N);
    int cnt = 0; // 현재 보고 있는 수가 몇번 등장했는지
    ll mxval = -pow(2, 62)-1; // 현재까지 가장 많이 등장한 수의 값
    int mxcnt = 0; // 현재까지 가장 많이 등장한 수의 등장 횟수
    for(int i=0; i<N; i++){
        if(i==0 || a[i-1] == a[i]) cnt++;
        // i가 0인 경우, 앞쪽 식이 true이기 때문에 a[i-1]을 참조하지 않음 
        else{
            if(cnt > mxcnt){
                mxcnt = cnt;
                mxval = a[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mxval = a[N-1]; // 제일 마지막 수가 몇 번 등장했는지 별도로 확인
    cout << mxval;

    return 0;
}