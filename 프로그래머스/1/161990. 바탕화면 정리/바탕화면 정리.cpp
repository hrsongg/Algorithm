#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int col_min = 100;
    int col_max = 0;
    int row_min = 100;
    int row_max = 0;
    for(int y=0; y<wallpaper.size(); y++){
        for(int x=0; x<wallpaper[0].size(); x++){
            if(wallpaper[y][x] == '#'){
                col_min = min(col_min, y);
                col_max = max(col_max, y);
                row_min = min(row_min, x);
                row_max = max(row_max, x);
            }
        }
    }
    answer.push_back(col_min);
    answer.push_back(row_min);
    answer.push_back(col_max+1);
    answer.push_back(row_max+1);
    return answer;
}