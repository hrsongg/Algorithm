// BOJ 10026 적록색약
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
char board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int area(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!vis[i][j]){
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // input
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n ;j++){
            cin >> board[i][j];
        }
    }

    int not_g = area(); // 적록색약이 아닌 사람

    // 초기화
    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+n, false);

    // 적록색약은 초록/ 빨강 구분 못하므로, 초록이면 빨강으로 변환
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 'G') 
                board[i][j] = 'R';
        }
    }

    int is_g = area(); // 적록색약인 사람
    cout << not_g << " " << is_g;
    
    return 0;
}
