// 15649 N과 M(1)
#include <bits/stdc++.h>
using namespace std;
int N, M;
int isused[10]; // 방문처리 배열
int arr[10]; // 길이가 m인 수열 배열

void func(int k){
    if(k == M){ // base condition
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++){
        if(!isused[i]){
            isused[i] = 1; // 방문 처리
            arr[k] = i;
            func(k+1); // 다음 단계 방문
            isused[i] = 0; // 방문 해제
        }
    }
    
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    func(0);

    return 0;
}