#include <bits/stdc++.h>
using namespace std;
int n;
int A[52];
int B[52];

int main(void){
    int ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n; i++){
        cin >> B[i];
    }
    sort(A, A+n, greater<>()); // 내림차순
    sort(B, B+n); // 오름차순
    for(int i=0; i<n; i++){
        int first = A[i];
        int second = B[i];
        ans += first * second;
    }
    cout << ans;

}
