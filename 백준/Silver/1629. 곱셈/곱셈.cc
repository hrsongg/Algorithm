// BOJ 1629 곱셈 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m){
    // a를 b번 곱한 수를 c로 나눈 나머지
    if(b==1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    
    if(b%2 == 0) return val; // 짝수일 때 
    return val * a % m; // 홀수일 때, val에 a를 한번 더 곱해서 답 내야함
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
    return 0;
}