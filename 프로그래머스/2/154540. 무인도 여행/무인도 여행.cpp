#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1 ,0, 0};
bool dist[102][102]; // 방문여부
int i_cnt = 0; // 섬 개수 
int col, row; // map의 행, 열

int bfs(vector<string>& maps, int x, int y){
    int area = maps[x][y] - '0'; // 해당 무인도 섬의 크기, char형이므로 변환 필요
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = true;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= col || ny < 0 || ny >= row) continue; // 범위 벗어나면 pass
            if(dist[nx][ny]|| maps[nx][ny] == 'X') continue; // 이미 방문 했거나, 바다이면 pass
            // 여기까지 왔으면 방문할 수 있는 곳
            q.push({nx, ny}); 
            dist[nx][ny] = true; // 방문처리
            area += (maps[nx][ny] - '0'); // 해당 위치 식량 추가해줌
        }
    }
    return area;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    memset(dist, 0, sizeof(dist)); // 0으로 초기화 
    col = maps.size(); // 행
    row = maps[0].size(); // 열
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(!dist[i][j] && maps[i][j] != 'X'){ // 아직 방문을 안했고, 바다가 아닐 때에만 탐색
                int area = bfs(maps, i, j); // bfs 탐색
                answer.push_back(area);
                i_cnt++; // 섬 개수 증가
            }
        }
    }
    if(answer.size() == 0) answer.push_back(-1); // 지낼 수 있는 무인도가 없으면 -1 return
    sort(answer.begin(), answer.end()); // 오름차순으로 정렬 후 return
    return answer;
}