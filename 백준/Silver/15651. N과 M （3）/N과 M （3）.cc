// 15651 N과 M(3)
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
// isused 방문 처리 배열을 안 써도 됨 

void func(int k){ // 현재 k개까지 수를 택했음
    if(k == M){ // m개를 모두 택했으면 
        for(int i=0; i<M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=N; i++){
        arr[k] = i; // k번째 수를 i로 정함
        func(k+1); // 다음 수를 정하러 한 단계 더 들어감 
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // input

    func(0); // logic

    return 0;
}