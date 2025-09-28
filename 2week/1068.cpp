#include <bits/stdc++.h>
using namespace std;
int n, r, temp, root, cnt;
vector<int> adj[54];
// 리프노드 수를 구하는 함수
void dfs(int here){
    bool leaf = true;
    for(int there : adj[here]){
        if(there == r) continue;
        leaf = false;
        dfs(there);
    }
    if(leaf) cnt++; // 전역 변수에 누적
}
int main(){
    cin >> n;
    // 트리 입력 (입력 정보는 부모 노드의 번호)
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1)root = i;
        else adj[temp].push_back(i);
    }
    // 지울 노드
    cin >> r;
    if(r == root){
        cout << 0 << "\n"; return 0;
    }
    // 트리 탐색은 무조건 루트에서 하는게 좋음
    dfs(root);
    cout << cnt << "\n";
    return 0;
}