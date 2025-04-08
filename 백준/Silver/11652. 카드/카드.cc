// 11652 카드
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map <ll, int> mp;
vector<pair<ll, int>> v;
int N;
ll num;

bool cmp(pair<ll, int> p1, pair<ll, int> p2){
    int cnta = 0, cntb = 0;
    cnta = p1.second; cntb = p2.second;
    if(cnta != cntb) return cnta > cntb;
    // 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것
    return p1.first < p2.first;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        mp[num]++;
    }
    
    vector<pair<ll, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first;

    return 0;
}