// 7662 이중 우선순위 큐
#include <bits/stdc++.h>
using namespace std;

multiset<int> ms; // 동일한 정수 삽입 가능하므로 

int T, k, n;
char sts;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> k;
        ms.clear(); // 테스트 케이스마다 초기화 
        while(k--){ // 각 테스트 데이터에 대해 
            //cout << "-- print --\n";
            cin >> sts >> n;
            if(sts == 'D'){ // 삭제
                if(ms.empty()) continue; // Q가 비어있는 상태에서 D 요청은 무시
                // Q가 비어있지 않다면 삭제 요청
                if(n==1){ // 최댓값 삭제
                    // 최댓값을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제
                    auto it1 = --ms.end();
                    int num = *it1;
                    ms.erase(ms.find(num));
                    
                }
                else{ // 최솟값 삭제
                    auto it2 = ms.begin();
                    int num = *it2;
                    ms.erase(ms.find(num));
                }

            }
            else{ // 삽입
                ms.insert(n);
            }
        }

        // 모든 연산 처리한 후, Q에 남아있는 값 중 최댓값/ 최솟값 출력 
        if(ms.empty()) cout << "EMPTY\n";
        else{
            auto mxit = --ms.end();
            auto mnit = ms.begin();
            cout << *mxit << " " << *mnit <<"\n";
        }
    }

    return 0;
}