#include <bits/stdc++.h>
using namespace std;
int n, m, ret, j, l, r, temp;
int a[11];
int main(){
    cin >> n >> m >> j;
    l = 1;
    for(int i = 0; i < j; i++){
        r = l + m - 1;
        cin >> temp;
        // 시작할 때 범위 안에 들면 pass
        if(l <= temp && temp <= r) continue;
        else{
            // 사과가 바구니 왼쪽 사이드보다 왼쪽인 경우 
            if(temp < l){
                // 그림 그려보면 왜 1 - temp인지 이해 빠름
                ret += (l - temp);
                // 이땐 l이 가장 먼저 사과 만나므로 갱신
                l = temp;
            }
            // 사과가 바구니 오른쪽 보다 오른쪽인 경우
            else{
                l += (temp -r);
                ret += (temp - r);
            }
        }
    }
    cout << ret << "\n";
}