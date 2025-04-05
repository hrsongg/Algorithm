 // 1992 쿼드트리
#include <bits/stdc++.h>
using namespace std;
string board[66];
int N; // 1~64

void func(int x, int y, int len){
    char num = board[x][y];
    if(len == 1){
        cout << num;
        return;
    }
    // (x,y)부터 길이가 len인 정사각형만큼 탐색 
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(board[i][j] != num){  // 값이 다르면 
                cout << "(";
                len /= 2; // 길이를 줄여서 다시 탐색 
                func(x, y, len);
                func(x, y+len, len);
                func(x+len, y, len);
                func(x+len, y+len, len);
                cout << ")";
                return;
            }
        }
    }
    cout << num;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> board[i];
    
    func(0, 0, N);

    return 0;
}