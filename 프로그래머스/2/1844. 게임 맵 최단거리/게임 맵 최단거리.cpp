#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int N = maps.size(); // 행
    int M = maps[0].size(); // 열
    memset(dist, -1, sizeof(dist)); // -1로 초기화 
    
    queue<pair<int, int>> q; // BFS
    dist[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] != -1 || maps[nx][ny] != 1) continue;
            // 이미 방문을 했거나, 벽이라면 pass
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    answer = dist[N-1][M-1];
    
    return answer;
}