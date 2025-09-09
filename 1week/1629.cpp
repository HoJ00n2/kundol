#include <bits/stdc++.h>
using namespace std;
// 일단 정수범위 초과하므로 long long 선언 
long long a,b,c;

long long go(long long a, long long b){
    // 기저 조건
    if(b == 1) return a % c;

    // 10^8 = (10^4) * (10^4) 이렇게 반으로 쪼개지므로
    long long ret = go(a, b / 2);
    // 다 쌓이기 전에 미리 계산
    ret = (ret * ret) % c;
    // b가 홀수일때 처리 반으로 안나눠지니까 a 한번 더 곱해줌
    // 2^5 = 2^2 * 2^2 * 2
    // b % 2 == 1 (true) -> 홀수인 경우
    if(b % 2)ret = (ret * a) % c;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a,b) << "\n";
    return 0;
}