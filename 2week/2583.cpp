#include <bits/stdc++.h>
using namespace std;
int m,n,k,ret,width, lx, ly, rx, ry, nx, ny;
int a[101][101], visited[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> w;
int dfs(int y, int x){
    visited[y][x] = 1;
    // 시작점 넓이 카운트
    int ret = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i];
        if(ny < 0 || ny >= m || nx < 0 || nx >= n || a[ny][nx] > 0) continue;
        if(visited[ny][nx]) continue;
        // 덩어리 넓이값 누적 
        ret += dfs(ny, nx);
    }
    return ret;
}
int main(){
    cin >> m >> n >> k;
    // k번 동안 직사각형 좌표 입력
    for(int d = 0; d < k; d++){
        cin >> lx >> ly >> rx >> ry;
        // 입력 크기만큼 색칠
        for(int i = ly; i < ry; i++){
            for(int j = lx; j < rx; j++){
                a[i][j] = 1;
            }
        }
    }
    // 덩어리 찾기
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 0 && visited[i][j] == 0){
                w.push_back(dfs(i, j));
            }
        }
    }
    sort(w.begin(), w.end());
    cout << w.size() << "\n";
    for(int a : w) cout << a << " ";
    return 0;
}