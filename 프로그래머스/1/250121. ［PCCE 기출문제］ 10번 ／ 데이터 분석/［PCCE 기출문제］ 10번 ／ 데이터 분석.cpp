#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    // vector<vector<int>> answer;
    map<string, int> ext_idx = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};
    vector<vector<int>> tmp;

    // data에서 ext 값이 val_ext 보다 작은 데이터만 뽑은 후
    for(auto d: data){
        if(d[ext_idx[ext]] < val_ext){
            tmp.push_back(d);
        }
    }
    
    
    // sort_by에 해당하는 값을 기준으로 오름차순으로 정렬
    sort(tmp.begin(), tmp.end(), [&](const auto& a, const auto& b) {
        return a[ext_idx[sort_by]] < b[ext_idx[sort_by]];
    });
    
    return tmp;
}