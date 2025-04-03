// ???
// BOJ 11729 하노이 탑 이동 순서 
#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){
    // 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }

    // n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    func(a, 6-a-b, n-1);
    // n번 원판을 기둥 a에서 기둥 b로 옮긴다.
    cout << a << ' ' << b << '\n';
    // n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다. 
    func(6-a-b, b, n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1<<k) -1 << '\n';
    func(1, 3, k);

    return 0;
}