// 6603 로또: 조합
#include <bits/stdc++.h>
using namespace std;
int k, T;
int num[15];
int arr[15];

void func(int dep, int st) {
    if (dep == 6) {
        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = st; i < k; i++) {
        arr[dep] = num[i];
        func(dep + 1, i + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> num[i];
        func(0, 0);
        cout << '\n'; // 1TC 후 줄 바꿈
    }
    return 0;
}