#include <bits/stdc++.h>
using namespace std;
// count 배열 만들기 최대칸 만큼 (1~100 사이므로) 100
// 각 겹치는 시간 누적
int schedule[101];
int result;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < 3; i++){
        int s, e;
        cin >> s >> e;
        for(int j = s; j < e; j++){
            schedule[j]++;
        }
    }

    // 겹치는 정도에 따라 가격 계산
    for(int i = 0; i < 100; i++){
        if(schedule[i+1]==1){
            result += 1*a;
        }
        else if(schedule[i+1]==2){
            result += 2*b;
        }
        else if(schedule[i+1]==3){
            result += 3*c;
        }
    }
    cout << result << "\n";
    return 0;
}