// BOJ 3273 두 수의 합 
#include <bits/stdc++.h>
using namespace std;
int arr[100002]; // 각 자연수의 존재 여부 저장
bool available[2000002]; //

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    int ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;
    for(int i=0; i<n; i++){
        // x-arr[i]가 양수이고 available에 존재하는지 확인
        if(x-arr[i] > 0 && available[x-arr[i]]) ans++;
        available[arr[i]] = true;
    }
    cout << ans;
    return 0;
}
