// BOJ 2667 단지번호 붙이기 
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
string board[27];
int dist[27][27]; // 방문(1), 미방문(0)만 체크 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int danji_cnt; // 단지 수 카운트 
vector<int> danji; // 단지별 크기 정보 저장 벡터 

int bfs(int i, int j){
    int area = 0; // 단지의 최대값

    queue<pair<int, int>> q;
    q.push({i, j});
    dist[i][j] = 1; // 시작점 방문처리 

    while(!q.empty()){
        area++; // 단지의 크기 증가 !!
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            // 범위를 벗어나면 방문하지 않는다 
            if(board[nx][ny] == '0'||  dist[nx][ny]) continue;
            // 집이 아닌 곳, 이미 방문한 곳은 방문하지 않는다
            q.push({nx, ny});
            dist[nx][ny] = 1; // 방문처리 
        }
    }
    return area;
}

void debug(void){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // board 초기화 
    memset(dist, 0, sizeof(dist));
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    

    // bfs 체크
    danji_cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '1' && dist[i][j] == 0){
                // board가 집이고 아직 방문 안 했을 때에만 BFS 
                danji_cnt++; // 단지 수 카운트 증가 
                danji.push_back(bfs(i, j)); // 단지 크기 저장 
            }
        }
    }

    sort(danji.begin(), danji.end());
    cout << danji_cnt << "\n";
    for(int i=0; i<danji.size(); i++){
        cout << danji[i] << "\n";
    }

    // debug();
    return 0;
}