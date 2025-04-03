// BOJ 1074 Z
#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    // 2^n * 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수 
    if(n==0){ // base condition
        return 0;
    }
    int half = pow(2, n-1);
   // 재귀식  
   if(r < half && c < half){ // 1사분면
        return func(n-1, r, c);
   }
   else if(r < half && c >= half){ // 2사분면
        return half*half + func(n-1, r, c-half);
   }
   else if(r >= half && c < half) { // 3사분면
        return 2*half*half + func(n-1, r-half, c);
   }
   else{ // 4사분면
        return 3*half*half + func(n-1, r-half, c-half);
   }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N, r, c);

    return 0;
}