// 1431 시리얼 번호
#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> v;

bool cmp(const string& a, const string& b){
    if(a.size() != b.size()) return a.size() < b.size();
    int sum_a = 0; int sum_b = 0;
    int num = 0;
    for(char c: a){
        if(isdigit(c)){
            num = c-'0';
            sum_a += num;
        }
    }
    for(char c: b){
        if(isdigit(c)){
            num = c-'0';
            sum_b += num;
        }
    }
    if(sum_a != sum_b) return sum_a < sum_b;
    return a < b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        string s = ""; 
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<N; i++) cout << v[i] << "\n";

    return 0;
}