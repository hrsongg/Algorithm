#include <bits/stdc++.h>
using namespace std;
int gisa[100002];
// 약수의 개수 찾기
int factor(int n){
    int cnt = 2;
    if(n==1) return 1;
    for(int i=2; i<=n/2; i++){
        if(n%i == 0) cnt++;
    }
    return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    memset(gisa, 0, sizeof(gisa));
    for(int i=1; i<number+1; i++){
        gisa[i] = factor(i); // 약수의 개수
        if(gisa[i] > limit) { // limit 이상이면
            gisa[i] = power; // power로 대체 
        }
        
        answer += gisa[i];
    }
    
    return answer;
}