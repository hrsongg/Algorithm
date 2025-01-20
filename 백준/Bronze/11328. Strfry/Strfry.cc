// BOJ 11328 Strfry
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; // 0 ~ 1001
    cin >> n;
    while(n--){
        int a[26] = {}; // 각 문자의 개수를 저장하는 배열
        string s1, s2;
        cin >> s1 >> s2;

        for(auto c: s1) a[c-'a']++; // s1에서 문자열이 존재하면 +
        for(auto c: s2) a[c-'a']--; // s2에서 문자열이 존재하면 -

        // 배열 값이 모두 0이면 Possible
        // 배열 값 중 하나라도 0이 아닌 값이 있으면 Impossible
        bool isPossible = true;
        for(int i: a){
            if(i != 0) isPossible = false;
        }

        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}
