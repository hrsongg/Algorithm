#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    vector<int> v;

    string ans = "";
    string s = to_string(n);
    for(auto c: s){
        int num = (int)(c-'0');
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<>());
    
    for(int i: v){
        ans += to_string(i);
    }
    
    long long answer = stoll(ans);
    return answer;
}