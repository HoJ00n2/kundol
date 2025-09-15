#include <bits/stdc++.h>
using namespace std;
int n, m, qy, qx, ny, nx, ret;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int visited[104][104];
int a[104][104];

void bfs(int y, int x){
    queue<pair<int,int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        tie(qy, qx) = q.front(); q.pop();
        for(int i = 0; i < 4; i ++){
            ny = qy + dy[i]; nx = qx + dx[i];
            // 범위초과
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
            if(a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[qy][qx] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0, 0);
    cout << visited[n-1][m-1] << "\n";
    return 0;
}