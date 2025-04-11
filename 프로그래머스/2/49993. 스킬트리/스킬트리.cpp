#include <bits/stdc++.h>

using namespace std;
set<char> prior; // 스킬이 중복해 주어지지 않습니다
int cnt = 0; // 가능한 스킬트리 개수 
char chk = 'A'; // skill 체크 문자
string order; // skill 

bool check_skill(string inp){ // inp: 체크해야할 스킬- BACDE
    // 주어진 skill이 선행 스킬 순서를 만족하는지 체크
    int idx = 0; // skill 체크하는 idx
    //bool flag = true; // 디폴트는 만족한다고 생각
    for(auto alp: inp){ // B - A - C - D - E 순서대로 확인
        if(prior.count(alp)){ // 확인해야할 문자열이 skill에 포함되는 문자열이면
            if(order[idx] != alp){ // 순서에 맞는 문자열인지 확인
                return false; // 순서에 맞지 않으니 더 확인할 필요 없음
            }
            else{ // 순서에 맞는다면
                idx++;
            }
        }
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    order = skill;
    for(auto c: skill){ // skill의 존재 여부를 확인하는 집합
        prior.insert(c);
    }
    for(auto inp: skill_trees){ // inp: 체크해야할 스킬- BACDE
        if(check_skill(inp)) answer++; // 만족하면 answer 증가
    }
    
    return answer;
}