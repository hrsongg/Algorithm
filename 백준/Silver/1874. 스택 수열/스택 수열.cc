// BOJ 1874 스택 수열
#include<iostream>
#include<cstring>
#include<algorithm>
#include <stack>
#define MAX 100001

using namespace std;
int N;
int arr[MAX];
stack<int> st;
vector<char> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 1;
    
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        
        while(cnt <= num){
            v.push_back('+');
            st.push(cnt++);
        }
        if(num == st.top()){
            st.pop();
            v.push_back('-');
        }
        else{
            cout << "NO";
            return 0;
        }
        
    }
    
    for(int i=0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    
    
    return 0;
}

