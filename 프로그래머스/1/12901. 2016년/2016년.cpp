#include <bits/stdc++.h>
using namespace std;
string arr[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b) {
    string answer = "";
    int day = 0;
    // 31: 1 3 5 7 8 10 12  
    // 30: 4 6 9 11
    // 29: 2
    for(int i=1; i<a; i++){
        if(i==2) day += 29; // 윤년 29일
        else if(i==4 || i==6 || i==9 || i==11) day += 30;
        else day += 31;
    }
    day += b;
    answer = arr[day % 7];
    
    return answer;
}