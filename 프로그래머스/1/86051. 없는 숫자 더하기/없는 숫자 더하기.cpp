#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
    int arr[10];
    int answer = 0;
    memset(arr, 0, sizeof(arr));
    
    for(int n: numbers){
        arr[n]++;
    }
    for(int i=0; i<10; i++){
        if(arr[i] == 0){
            answer += i;
        }
    }
    
    return answer;
}