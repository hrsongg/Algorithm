// BOJ 1475 방 번호
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    unordered_map<char, int> uo;
   
    int N; 
    int ret = 0;
    bool flag = false;

    cin >> N;

    string num = to_string(N);
    for(int i=0; i<num.size(); i++){
        if(num[i] == '9' || num[i] == '6'){
            uo['6']++;
            flag = true;
        }
        else uo[num[i]]++;
    }
    
    if(flag){ // 6 or 9가 존재하면
        if(uo['6'] % 2 == 1){
            uo['6'] = (uo['6'] / 2) + 1;
        }else{
            uo['6'] = uo['6']/2;
        }
    }

    for(auto alp: uo){
        ret = max(ret, alp.second);
    }
    cout << ret;

    return 0;
}
