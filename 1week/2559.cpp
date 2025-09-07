// N : 1 ~ 10만
// k : 1 ~ 10만 - 1 (사이값이므로 1은 빼준다.)
// 온도는 -100 ~ 100
// 연속된 온도의 합이 "최대"? >> "구간합"을 떠올려야 prefix sum, psum
// psum[i] = psum[i -1] + a[i]
// 이 문제의 "최소"는 ? : -100이 10만일 연속 될 때 -> 1천만
// 최대값은 어디서부터?

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
// 최소값인 ret는 -1천만인데, 버퍼인 4를 주어 넉넉하게 (예외 안걸리도록)
int n, k, temp, psum[100001], ret = -10000004;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> temp; // 1 2 3 4 5 이렇게 입력해도 처리됨
        psum[i] = psum[i - 1] + temp;
    }
    // 연속 k일의 구간합
    for(int i = k; i <= n; i++){
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout << ret << "\n";
    return 0;
}