#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<string>> park, int ny, int nx, int mat){
    for(int i=0; i<mat; i++){
        for(int j=0; j<mat; j++){
            int y = ny + i;
            int x = nx + j;
            if(y < 0 || x < 0 || y >= park.size() || x >= park[0].size()) return false;
            if(park[y][x] != "-1") return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    sort(mats.begin(), mats.end(), greater<>()); // 내림차순
    vector<pair<int, int>> empty;
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[0].size(); j++){
            if(park[i][j] == "-1"){
                empty.push_back({i, j});
            }
        }
    }
    
    for(auto mat: mats){
        for(auto p: empty){
            int ny = p.first;
            int nx = p.second;
            if(check(park, ny, nx, mat)) return mat;
        }
    }
    
    return -1;
}