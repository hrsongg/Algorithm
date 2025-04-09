#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long ret = 0;
int arr[12];

int main(void){
    cin >> n >> k;
    // 각 동전의 개수는 무한
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // 오름차순으로 주어짐 (정렬 되어 있음)
    }
    
    for(int i = n-1; i>=0; i--){
        if(k/arr[i] > 0) { // 몫이 존재한다면
            ret += k / arr[i];
            k = k % arr[i];
        }
    }
    cout << ret;
    
    // K원을 만드는데 필요한 동전 개수의 최솟값
    return 0;
}
