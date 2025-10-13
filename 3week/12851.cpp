#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int visited[MAX + 4];
long long cnt[MAX + 4];
int main(){
    int n, m;
    cin >> n >> m;
    // 반례 처리 : 이미 같은 위치일 때 미리 커트(백트래킹)
    // 사실 이 문제에선 안해도 되지만 나중엔 같은 경우도 테스트하기 
    if(n == m){
        puts("0"); puts("1");
        return 0;
    }
    // 최단거리이므로 BFS로 처리
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(q.size()){
        int here = q.front(); q.pop();
        // 3가지 이동 경우의 수에 대해서 구현
        for(int next : {here + 1, here - 1, here * 2}){
            // 범주 내에서만 탐색 (ny, nx) 범위 따지는 것 처럼
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    q.push(next);
                    // 최단거리 저장
                    visited[next] = visited[here] + 1;
                    // 경우의수 저장 (경우의 수는 더하기로 표현!)
                    cnt[next] += cnt[here];
                }
                // 이 경우는 뭐지?
                // next노드로 오는 3가지 경우 중 다른 방법으로 왔을 때
                // if문 만으로는 3가지 중 1가지 방법만 저장됨 
                else if(visited[next] == visited[here] + 1){
                    cnt[next] += cnt[here];
                }
            }
        }
    }
    // 첫 노드 시간을 0이 아닌 1로 잡았으므로 -1 해줘야함
    cout << visited[m] - 1 << "\n";
    cout << cnt[m] << "\n";
    return 0;
}