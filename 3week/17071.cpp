#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000;
// "동생"의 이동좌표 2개로 한것은 홀수, 짝수초 나누기 위함
// [50만][50만] 으로 표현하면 공간복잡도 소요되므로 최소화한 것
int visited[2][max_n + 4];
int a, b, ok, turn = 1;
int main(){
    cin >> a >> b;
    if(a==b){cout << 0 << "\n"; return 0;}
    queue<int> q;
    visited[0][a] = 1;
    q.push(a);
    while(q.size()){
        // 초마다 늘어나는 동생 이동속도
        b += turn;
        if(b > max_n)break;
        // 만나는 case 1 : 짝수턴 전에 수빈이가 이미 들렀다면 >> 만날 수 있음
        if(visited[turn % 2][b]){
            ok = true;
            break;
        }
        // 플루드필 알고리즘 >> 단계별로 색깔 칠하는 알고리즘
        // 매 단계(level = qSize)마다 경우의수에 대해 체크 
        int qSize = q.size();
        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();
            // nx는 수빈이가 이동한 것에 대한 구현
            for(int nx : {x + 1, x - 1, x * 2}){
                // overflow 혹은 짝수턴 전에 방문했다면 continue
                // 짝수턴 전 방문은 왜 continue? >> visited는 동생이라 그런가 (수빈이는 상관 없을 것 같은데)
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                // 만나는 case 2 : 수빈이가 이동해서 동생에 다다른 경우
                // 예제 (5, 17)인 경우
                if(nx == b){
                    ok = 1; break;
                }
                // 다음 level 탐색
                q.push(nx);
            }
            if(ok)break;
        }
        if(ok)break;
        turn++;
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}