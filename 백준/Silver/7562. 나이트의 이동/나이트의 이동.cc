// BOJ 7562 나이트의 이동
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char board[302][302];
int dist[302][302];
int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};
int n;

int bfs(int sx, int sy, int ex, int ey){
    // 시작점 == 도착점이면 거리 0
    if(sx == ex && sy == ey) return 0;

    queue<pair<int, int>> q;
    dist[sx][sy] = 1;
    q.push({sx, sy});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int dir=0; dir<8; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});

        }
    }
    return dist[ex][ey] -1;
}  


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int sx, sy, ex, ey, t;
    cin >> t;
    for(int i=0; i<t ; i++){
        memset(dist, 0, sizeof(dist));
        cin >> n;
        cin >> sx >> sy;
        cin >> ex >> ey;
        
        cout << bfs(sx, sy, ex, ey) << "\n";
    }
}