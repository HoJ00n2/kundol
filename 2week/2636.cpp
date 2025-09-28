#include <bits/stdc++.h>
using namespace std;
int n, m, ny, nx, a[101][101], visited[101][101], cheese, cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;
void dfs(int y, int x){
    visited[y][x] = 1;
    // if(a[y][x]==1){
    //     v.push_back({y, x});
    //     return;
    // }
    for(int i = 0; i < 4; i++){
        ny = y + dy[i]; nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
        if(a[ny][nx] == 0)dfs(ny, nx);
        if(a[ny][nx] == 1){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
        }
        // dfs(ny, nx);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    while(true){
        fill(&visited[0][0], &visited[0][0] + 101*101, 0);
        v.clear();
        dfs(0, 0);
        if(v.size())cheese = v.size(); // 남은 치즈 개수
        for(pair<int, int> p : v){
            a[p.first][p.second] = 0;
        }
        // 다 녹았는지 체크
        bool flag = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1)flag=1;
            }
        }
        cnt++;
        if(!flag) break; // 다 녹았다면 탈출
    }
    cout << cnt << "\n" << cheese << "\n";
    return 0;
}