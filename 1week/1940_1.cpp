// 2중 for문으로 조합
#include <bits/stdc++.h>
using namespace std;
int n, m, a[15001], cnt;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    // 없어도 정답은 맞지만 재료 최대값이 10만 넘으므로 20만 못넘김, 빠르게 넘기려고
    if(m > 200000) cout << 0 << "\n";
    // n개중 2개 뽑는다 -> Combination!! nC2
    // 2개 뽑으므로 2중 for문 구현 가능
    else{
        for(int i = 0; i < n; i++){
            // int j = i 도 되는데, 중복으로 뽑진 않으므로 i+1부터 시작
            for(int j = i+1; j < n; j++){
                if(a[i] + a[j] == m)cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}