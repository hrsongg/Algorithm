#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto alp: s){ // char형
        if(isspace(alp)){ // 공백이면
            answer += " ";
        }
        else{ // 알파벳 대문자 또는 소문자 
            if(alp >= 'a' && alp <= 'z'){ // 소문자
                alp = (alp - 'a' + n) % 26 + 'a';
            }
            else{ // 대문자
                alp = (alp - 'A' + n) % 26 + 'A';
            }
            answer += alp; 
        }
    }
    return answer;
}