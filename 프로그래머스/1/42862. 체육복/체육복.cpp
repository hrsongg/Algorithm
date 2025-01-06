#include <bits/stdc++.h>
using namespace std;
int arr[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    fill(arr, arr+1+n, 1);
    for(auto r: reserve){
        arr[r] += 1;
    }
    for(auto l: lost){
        arr[l] -= 1;
    }
    for(int idx=1; idx<=n; idx++){
        if(arr[idx] == 0){
            if(idx-1 >= 1 && arr[idx-1] >= 2){ // prev
                arr[idx-1] -= 1;
                arr[idx] += 1;
            }
            else if(idx+1 <= n && arr[idx+1] >= 2){ // next
                arr[idx+1] -= 1;
                arr[idx] += 1;
            }
        }
    }
    
    for(auto idx: lost){

    }
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
        if(arr[i]>0) answer += 1;
    }
    
    return answer;
}