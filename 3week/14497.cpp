#include <bits/stdc++.h>
using namespace std;
int n, m, ret, x_1, x_2, y_1, y_2;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char a[304][304]; int visited[304][304];
int main(){
    cin >> n >> m;
    cin >> y_1 >> x_1 >> y_2 >> x_2;
    y_1--,x_1--,y_2--,x_2--;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    queue<int> q;
    // 보통 큐에는 {y, x}로 담는데 이걸 1차원으로 담기 위함
    // [300][300]을 표현하기 위해 1000을 곱
    // 이때 1천은 주어진 300보다 좀 더 큰값으로 잡는게 좋음 (오버플로우 방지)
    // 추후 q에 대해 몫, 나머지 연산자로 y,x를 할당할 것임
    q.push(1000 * y_1 + x_1);
    visited[y_1][x_1] = 1;
    int cnt = 0;
    // 파동이 범인 만날때 까지 탐색
    while(a[y_2][x_2] != '0'){
        // 여기다 둠으로써 1을 만났을 때만 cnt 추가
        cnt++;
        queue<int> temp;
        // q.size만큼 bfs
        while(q.size()){
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
                visited[ny][nx] = cnt;
                // 벽이나 범인 만났다면
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                // 0이라면
                else q.push(1000 * ny + nx);
            }
        }
        // 1이나 벽 만났을 때를 기점으로 다시 q 탐색 
        // while(q.size()) 바깥에 선언한 것이므로 이미 기존 q는 없는 상태
        // 이 때 1 만났을 때의 좌표들을 q에 넣어서 재가동
        q = temp;
    }
    cout << visited[y_2][x_2];
    return 0;
}