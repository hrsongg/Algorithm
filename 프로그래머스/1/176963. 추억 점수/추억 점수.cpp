#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> um;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0; i<name.size(); i++){
        um[name[i]] = yearning[i];
    }
    for(auto pic: photo){
        int val = 0;
        for(auto nm: pic){
            val += um[nm];
        }
        answer.push_back(val);
    }
    
    return answer;
}