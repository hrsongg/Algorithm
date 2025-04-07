// 15652 N과 M(4) : 중복 조합 
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void func(int k){ // 현재 k개까지 수를 택했음    
    if(k == M){ // M개를 모두 택했으면 
        for(int i=0; i<M; i++)
            cout << arr[i] << " "; // arr에 기록해둔 수를 출력 
        cout << "\n";
        return;
    }
    int st = 1; // 시작지점, k=0일 때에는 st=1
    if(k != 0) st = arr[k-1]; // k!=0일 때에는 st=arr[k-1]
    for(int i = st; i <= N; i++){
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