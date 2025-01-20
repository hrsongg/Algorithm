 // BOJ 1919 애너그램 만들기
#include <bits/stdc++.h>
using namespace std;
int arr[2][26] = {0};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1; string s2;
    cin >> s1 >> s2;
    int ret = 0;

    for(auto s: s1){
        arr[0][s-'a']++;
    }
    for(auto s: s2){
        arr[1][s-'a']++;
    }
    for(int i=0; i<26; i++){
        ret += abs(arr[0][i] - arr[1][i]);
    }
    cout << ret;
    return 0;
}