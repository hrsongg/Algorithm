// BOJ 2178 미로탐색
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 101

int board[MAX][MAX];
//bool visited[MAX][MAX] = {0}; // 해당 칸을 방문했는지 여부를 저장
int dist[MAX][MAX]; // visited 겸용
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int cnt = 1e9; // 이동 최소값

void init(void){
    memset(dist, -1, sizeof(dist));
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &board[i][j]);
        }
    }
}

void debug(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout <<  dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void solution(void){
    init();
    
    queue<pair<int, int>> q;
    dist[1][1] = 1;
    q.push({1, 1});
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
            if(board[nx][ny]!=1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }
    //debug();
    cnt = dist[n][m];
    printf("%d", cnt);
}

int main(void){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    solution();
    
}
