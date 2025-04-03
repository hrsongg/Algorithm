// BOJ 1780 종이의 개수 
#include <bits/stdc++.h>
using namespace std;
int board[2190][2190];
// 2187
int ans[3]; 

void func(int x, int y, int len){
    int num = board[x][y];
    if(len == 1){ // base condition
        // len이 1일 땐, 종이를 더이상 자를 필요가 없다  
        if(num == -1) ans[0]++;
        else if(num == 0) ans[1]++;
        else ans[2]++;
        return;
    }
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(board[i][j] != num){
                len /= 3;
                func(x, y, len); 
                func(x, y + len,  len); 
                func(x, y + len*2,  len);
                func(x + len, y, len); 
                func(x + len, y + len,  len); 
                func(x + len, y + len*2,  len);
                func(x + len*2, y, len); 
                func(x + len*2, y + len,  len); 
                func(x + len*2, y + len*2,  len);
                return;
            }
        }
    } 
    // 모든 종이 조각이 같으면 값 증가 
    if(num == -1) ans[0]++;
    else if(num == 0) ans[1]++;
    else ans[2]++;  
}

int main(void){
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    func(0, 0, n);
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];

    return 0;
}