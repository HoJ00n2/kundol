#include <bits/stdc++.h>
using namespace std;
char a[51][51];
string s;
int visited[51][51], ret, ny, nx, n, m, qy, qx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int bfs(int y, int x){
    int cnt = 1; // 시간
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        pair<int, int> cur = q.front(); q.pop();
        qy = cur.first; qx = cur.second;
        for(int i = 0; i < 4; i++){
            ny = qy + dy[i]; nx = qx + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            cnt++;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] = 'L' && !visited[i][j]){
                ret = max(ret, bfs(i, j));
            }
        }
    }
    return 0;
}