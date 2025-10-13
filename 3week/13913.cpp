#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000; // 동생은 99999, 수빈이는 6만 대에 있는 경우 고려
int visited[MAX + 4], pre[MAX + 4];
long long a[MAX + 4];
int n, k, ret, here, cnt;
vector<int> v;
int main(){
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(q.size()){
        here = q.front(); q.pop();
        if(here == k){
            ret = visited[k];
            break;
        }
        for(int next : {here + 1, here - 1, here * 2}){
            if(next >= 0 && next < MAX){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[here] + 1;
                    // 지나온 경로 담기
                    pre[next] = here;
                }
            }
        }
    }
    // 동생 위치에서 시작해서 내 시작위치로 올때 까지 저장경로 탐색
    // k 다음은 pre[i]에 있는 값들로 재귀 탐색
    for(int i = k; i != n; i = pre[i]){
        v.push_back(i);
    }
    // 수빈이 시작위치 담기
    v.push_back(n);
    cout << ret - 1 << "\n";
    // 저장경로 출력
    reverse(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    return 0;
}