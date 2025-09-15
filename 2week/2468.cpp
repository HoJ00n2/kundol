#include <bits/stdc++.h>
using namespace std;
int n, nx, ny, max_ret;
int visited[101][101], a[101][101];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, int depth){
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(!visited[ny][nx] && a[ny][nx] > depth) dfs(ny, nx, depth);
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    // 높이 번 만큼 for문해서 탐색
    for(int d = 0; d < 101; d++){
        // ret, visiited는 매번 초기화
        int ret = 0;
        memset(visited, 0, sizeof(visited));
        // 비가 k만큼 올 때의 안전 영역 개수 구하기
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // 여기도 d 이상 영역만 찾아야함 (덩어리)
                if(a[i][j] > d && !visited[i][j]){
                    dfs(i, j, d);
                    ret++;
                }
            }
        }
        max_ret = max(max_ret, ret);
    }
    cout << max_ret << "\n";
}