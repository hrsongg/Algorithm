#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    queue<string> q1;
    queue<string> q2;

    for(auto s: cards1){
        q1.push(s);
    }
    for(auto s: cards2){
        q2.push(s);
    }

    for(auto s: goal){
        if(q1.front() == s){
            q1.pop();
        }
        else if(q2.front() == s){
            q2.pop();
        }
        else{
            return "No";
        }
    }
    
    return "Yes";
    
}