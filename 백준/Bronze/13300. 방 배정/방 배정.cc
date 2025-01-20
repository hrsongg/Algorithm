// BOJ 13300 방 배정
#include <bits/stdc++.h>
using namespace std;
int student[6][2] = {0};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k, s, y;
    int ret = 0;
    cin >> n >> k;
    for(int i=0; i<n; i++){ // 성별 s = {0, 1}, 학년 y= {1, 2, 3, 4, 5, 6}
        cin >> s >> y;
        student[y-1][s]++;
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<2; j++){
            student[i][j] = (student[i][j] + (k-1))/k;
            ret += student[i][j];
        }
    }

    cout << ret;

    return 0;
}
