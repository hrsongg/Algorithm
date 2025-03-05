// BOJ 1926 그림
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define MAX 501

int board[MAX][MAX];
bool visited[MAX][MAX]; // 해당 칸을 방문했는지 여부를 저장
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int pic_size = 0; // 그림의 최대값
int cnt = 0; // 그림의 수

void init(void){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }
}

void solution(void){
    init();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(board[i][j]==0 || visited[i][j]) continue;
            cnt++;
            // BFS
            queue<pair<int, int>> q;
            visited[i][j] = 1;
            q.push({i, j});
            int area = 0;
            while(!q.empty()){
                area++;
                pair<int, int> cur = q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
                    if(visited[nx][ny] || board[nx][ny] == 0) continue;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            pic_size = max(pic_size, area);
        }
    }
    cout << cnt << "\n" << pic_size;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solution();
}
