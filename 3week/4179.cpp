#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, sy, sx, y, x, ret;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int fire_check[1004][1004], person_check[1004][1004];
char a[1004][1004];
bool in(int y, int x){
    if(y < 0 || y >= n || x < 0 || x >= m)return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    queue<pair<int, int>> q;
    cin >> n >> m;
    fill(&fire_check[0][0], &fire_check[0][0] + 1004*1004, INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            // 불 지훈이 시작, 좌표 저장 (불 시작좌표는 여러개 가능)
            if(a[i][j] == 'F'){
                fire_check[i][j] = 1;
                q.push({i, j});
            }else if(a[i][j] == 'J'){
                sy = i, sx = j;
            }
        }
    }
    // 불 먼저 이동
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위 체크
            if(!in(ny, nx)) continue;
            if(fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    // 사람 이동
    person_check[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        // 사람 가장자리에 도달 -> 탈출 성공
        if(x == m - 1 || y == n - 1 || x == 0 || y == 0){
            ret = person_check[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(!in(ny, nx))continue;
            if(person_check[ny][nx] || a[ny][nx] == '#')continue;
            // 이동 좌표에 이미 불이 있을 때
            // if(fire_check[ny][nx] <= person_check[ny][nx])continue;
            // 아직 ny, nx 좌표에 값 할당 안해서 비교 불가
            if(fire_check[ny][nx] <= person_check[y][x] + 1)continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if(ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE \n";
    return 0;
}