// BOJ 2815 대피소: 조합
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> house;
int N, K, x, y;

vector<int> v; // next_permutation을 위한 벡터 
vector<int> checked;
vector<int> unchecked;

int calc(int xx, int yy, int nx, int ny){
    return abs(xx-nx) + abs(yy-ny);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie();
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        house.push_back({x, y});
    }
    
    // 초기값 세팅
    int ret = INT_MAX; // 최종 최대값
    for(int i=0; i<N; i++) v.push_back(i < K? 0: 1);
    
    do{
        unchecked.clear();
        checked.clear();
        for(int i=0; i<N; i++){
            if(v[i] == 0) {
                // 선택됨 
                checked.push_back(i);
            }
            else{
                unchecked.push_back(i);
            }
        }

        // 집에서 가장 가까운 대피소로 이동할 때 가장 긴 거리가 최소
        int dist_mx = 0;
        for(int j=0; j<unchecked.size(); j++){
            int dist = INT_MAX; // 선택한 집에서 대피소까지의 최단 거리가 될 값 
            for(int i=0; i<checked.size(); i++){
                int d = calc(house[checked[i]].X, house[checked[i]].Y, house[unchecked[j]].X, house[unchecked[j]].Y); // 임시 거리 
                dist = min(dist, d);
            }
            dist_mx = max(dist_mx, dist);
        }
        ret = min(ret, dist_mx);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ret;
    return 0;
}
