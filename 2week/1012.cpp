#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, sy, sx, ny, nx;
int visited[54][54], a[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0)continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx); 
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        int ret = 0;
        cin >> n >> m >> k;
        // 매번 배열 초기화
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));

        for(int j = 0; j < k; j++){
            cin >> sy >> sx;
            a[sy][sx] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] && !visited[i][j]){
                    dfs(i,j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }

}