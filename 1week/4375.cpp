#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    // eof 처리
    while(cin >> n){
        int cnt = 1; // 자리수 카운트
        long long a = 1;
        while(true){
            if(a % n == 0){
                cout << cnt << "\n";
                break;
            }
            // 자리수 올리기
            cnt++;
            // 1 > 11 > 111 > 1111 ...
            a = (a * 10 + 1) % n;
        }
    }
    return 0;
}