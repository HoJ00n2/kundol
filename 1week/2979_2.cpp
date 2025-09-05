#include <bits/stdc++.h>
using namespace std;
int a,b,c,result,s,e;
int cnt[101];
int main(){
    // 주차요금 입력
    cin >> a >> b >> c;
    // 3대 트럭의 시각 입력
    for(int i = 0; i < 3; i++){
        // 시각 입력 (s이상 ~ e미만)
        cin >> s >> e;
        for(int j = s; j < e; j++){
            cnt[j]++;
        }
    }
    // cnt배열 보고 가격 메기기
    for(int i = 0; i < 101; i++){
        // cnt가 0이 아니라면 (0빠르게 넘기기 위함)
        if(cnt[i]){
            if(cnt[i] == 1) result += a;
            else if(cnt[i] == 2) result += 2*b;
            else if(cnt[i] == 3) result += 3*c;
        }
    }
    // 결과 출력
    cout << result << "\n";
    return 0;
}