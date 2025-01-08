#include <bits/stdc++.h>
using namespace std;
// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, 
// k번째에 있는 수를 구하려 합니다.
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto v: commands){
        int i = v[0];
        int j = v[1];
        int k = v[2];
        vector<int> sorted(array.begin()+i-1, array.begin()+j);
        sort(sorted.begin(), sorted.end());
        answer.push_back(sorted[k-1]);
    }
    
    return answer;
}