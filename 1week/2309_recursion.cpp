#include <bits/stdc++.h>
using namespace std;
int a[9];
int n = 9, r = 7;

// 이번 경우는 bruteforce로 모든 경우의 수를 다 만들고
// index 0 ~ 6까지 7개 총합이 100인지 확인
void solve(){
    int sum = 0;
    for(int i = 0; i < r; i++){
        sum += a[i];
    }
    if(sum == 100){
        sort(a, a + 7);
        for(int i = 0; i < r; i++) cout << a[i] << "\n";
        exit(0); // main함수까지 종료
    }
}
// 순열 재귀함수 (외우기!)
void makePermutation(int n, int r, int depth){
    // 기저 조건
    if (r == depth){
        solve();
        return;
    }
    // 재귀 구현부분 외우기!
    for(int i = depth; i < n; i++){
        swap(a[i], a[depth]);
        makePermutation(n, r, depth + 1);
        swap(a[i], a[depth]);
    }
    return ;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    makePermutation(n, r, 0);
    return 0;
}