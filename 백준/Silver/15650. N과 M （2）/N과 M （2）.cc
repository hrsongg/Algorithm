#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;

void print(vector<int> &v){
    for(int x: v){
        cout << x << " ";
    }
    cout << "\n";
}

void dfs(int start, vector<int> &v){
    if(v.size() == m){
        print(v);
        return;
    }
    for(int i=start; i<n; i++){
        v.push_back(i+1);
        dfs(i+1, v);
        v.pop_back();
    }
    return;
}

int main(void){
    cin >> n >> m;
    dfs(0, v);
    return 0;
}
