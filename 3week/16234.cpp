#include <bits/stdc++.h>
using namespace std;
int n, l, r, ret, sum;
int a[54][54], visited[54][54];
vector<pair<int, int>> v;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x, vector<pair<int, int>> &v){
    // 같은 컴퍼넌트 탐색
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])continue;
        // L < 차이 < R이라면
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] = 1;
            v.push_back({ny ,nx});
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}
int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        bool flag = 0; // 인구이동 발생 여부
        // 테스트 케이스마다 visited 초기화 
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    // 같은 연합(컴퍼넌트)을 담기 위해 v 초기화 
                    v.clear();
                    // 연합 찾기 위한 탐색 시작
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j, v);
                    // 연합이 없다면 넘어가기 
                    if(v.size() == 1) continue;
                    // 같은 연합끼리 인구이동
                    for(pair<int, int> b : v){
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) break;
        ret++;
    }
    cout << ret << "\n";
    return 0;
}