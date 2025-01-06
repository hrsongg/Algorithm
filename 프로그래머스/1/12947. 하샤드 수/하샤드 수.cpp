#include <bits/stdc++.h>
using namespace std;

bool solution(int x) {
    int num = 0;
    string snum = to_string(x);
    for(auto s: snum){
        num += s - '0';
    }
    if(x % num == 0){
        return true;
    }
    return false;
}