#include <bits/stdc++.h>
using namespace std;

int solution(int num) {
    long long n = num;
    long long answer = 0;
    while(n != 1){
        // n != 1인 동안 반복
        if(n % 2 == 0){ // 짝수이면
            n /= 2;
        }
        else{ // 홀수이면
            n *= 3;
            n += 1;
        }
        answer++;
        if(answer > 500) return -1;
    }
    
    return answer;
}