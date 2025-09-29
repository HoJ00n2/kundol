// 방문 cnt해서 가장 많은애 출력, 같으면 오름차순 출력
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[10004], ret, dp[10004], mx;
vector<int> adj[10004];
int dfs(int here){
    int cnt = 1;
    for(int there : adj[here]){
        if(visited[there])continue;
        visited[there] = 1;
        cnt += dfs(there);
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }
    // 각 경우에서 한번의 실행에 가장많은 해킹하는 번호찾기
    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        ret = dfs(i);
        dp[i] = ret;
        mx = max(ret, mx);
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == mx) cout << i << " ";
    }
    return 0;
}