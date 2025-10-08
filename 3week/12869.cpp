#include <bits/stdc++.h>
using namespace std;
int scv[3], n, visited[64][64][64];
// ny, nx처럼 for문 돌면서 각 경우들을 현재 노드값에서 빼서 next 노드값 확보
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
// 3개 변수를 큐에 담기 위한 struct, 원래는 tuple도 되지만 이건 귀찮음
struct A{
    int a, b, c;
};
queue<A> q; // 이렇게 3개변수 큐에 저장!
int bfs(int a, int b, int c){
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop(); // 구조체 자체가 pop
        // 0,0,0이 된 노드가 있다면 탈출 
        if(visited[0][0][0])break;
        for(int i = 0; i < 6; i++){
            // 트랜잭션에서 음수가 되는 것을 방지 
            // na, nb, nc는 인덱스이므로 음수면 안됨
            // 만약 체력이 음수가 됐다면 0으로 저장
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            if(visited[na][nb][nc]) continue;
            // level 표시 (최단거리를 위함)
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
    // 시작노드를 1로하고 다음 level은 1씩 증가, 하지만 우리는 공격횟수를 물었으므로 -1
    // 시작 노드를 0으로하면 -1 안해도 됨 
    return visited[0][0][0] - 1;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> scv[i];
    cout << bfs(scv[0], scv[1], scv[2]) << "\n";
    return 0;
}