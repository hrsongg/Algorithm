// BOJ 11328 Strfry
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // 0 ~ 1001
    cin >> n;
    string inp, oup;
    for(int i=0; i<n; i++){
        cin >> inp;
        cin >> oup;
        sort(inp.begin(), inp.end());
        sort(oup.begin(), oup.end());

        if(inp == oup){
            cout << "Possible" << "\n";
        }
        else{
            cout << "Impossible" << "\n";
        }
    }
    
    return 0;
}
