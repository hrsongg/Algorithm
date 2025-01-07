#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<pair<int, int>> sorted_sizes;
    for(auto v: sizes){
        int minn = min(v[0], v[1]);
        int maxx = max(v[0], v[1]);
        sorted_sizes.push_back({minn, maxx});
    }
    
    sort(sorted_sizes.begin(), sorted_sizes.end()); 
    int max_w = 0;
    int max_h = 0;
    
    for(auto s: sorted_sizes){
        max_w = max(max_w, s.first);
        max_h = max(max_h, s.second);
    }
    cout << max_w << " " << max_h << "\n";
    answer = max_w * max_h;
    
    return answer;
}