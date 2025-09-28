#include <bits/stdc++.h>
using namespace std;
int n, m, ret, ny, nx;
int a[10][10], b[10][10];
vector<pair<int, int>> virus, wall;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// 바이러스 확산 코드
void dfs(int y, int x){
    // 확산
    for(int k = 0; k < 4; k++){
        nx = x + dx[k];
        ny = y + dy[k];
        if(nx < 0 || nx >= m || ny < 0 || ny >= n || b[ny][nx] == 1)continue;
        if(b[ny][nx] == 0){
            b[ny][nx] = 2;
            dfs(ny, nx);
        }
    }
}
int solve(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(b[i][j] == 0)cnt++;
        }
    }
    return cnt;
}
int main(){
    memset(a, -1, sizeof(a)); // 0의 개수를 셀거라 -1로 초기화
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0)wall.push_back({i, j});
            if(a[i][j] == 2)virus.push_back({i, j});
        }
    }
    // 벽 세우기 (순열 조햡)
    for(int i = 0; i < wall.size(); i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                // 0으로 되어있는 좌표 (y, x)에 1찍기
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                // 매 경우의수 마다 초기화 b는 벽 세워진 a 복사 
                memcpy(b, a, sizeof(a));
                // 바이러스 위치 기점으로 확산 시작
                for(pair<int, int> p : virus){
                    dfs(p.first, p.second);
                }
                ret = max(ret, solve());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}