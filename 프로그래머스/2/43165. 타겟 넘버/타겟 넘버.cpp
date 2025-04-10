#include <bits/stdc++.h>

using namespace std;
int tgt = 0;
int n_size = 0;
int cnt = 0;
int arr[22];

void func(int k, int tot){
    if(k == n_size){
        if(tot == tgt) cnt++;
        return;
    }
    func(k+1, tot+arr[k]);
    func(k+1, tot-arr[k]);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    tgt = target; n_size = numbers.size();
    for(int i=0 ;i<numbers.size(); i++) arr[i] = numbers[i];
    func(0, 0);
    answer = cnt;
    return answer;
}