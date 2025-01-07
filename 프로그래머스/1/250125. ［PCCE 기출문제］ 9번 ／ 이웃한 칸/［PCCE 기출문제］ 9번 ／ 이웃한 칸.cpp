#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string color = board[h][w];
    int col = board.size();
    int row = board[0].size();
    for(int dir = 0; dir < 4; dir++){
        int ny = h + dy[dir];
        int nx = w + dx[dir];
        if(ny < 0 || nx < 0 || ny >= col || nx >= row) continue;
        if(board[ny][nx] == color) answer++;
    }
    
    return answer;
}