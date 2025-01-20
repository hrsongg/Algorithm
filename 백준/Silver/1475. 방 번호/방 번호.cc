// BOJ 1475 방 번호
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    int N; 
    int arr[10] = {};
    int ret = 0;

    cin >> N;
    while(N){ // 일의 자리부터 자리 수 추출
        arr[N%10]++; 
        N /= 10;
    }

    for(int i=0; i<10; i++){
        if(i == 6 || i == 9) continue;
        ret = max(ret, arr[i]);
    }
    ret = max(ret, (arr[6] + arr[9] + 1) / 2); // 올림값 처리 
    cout << ret;
    return 0;
}
