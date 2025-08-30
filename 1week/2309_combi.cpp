// combination으로 푸는 방법
// 100 + A + B = 모든 난쟁이 키의 합
// 100 = 모든 난쟁이 키의 합 - A - B 이므로 이를 성립하는 A,B 2개 뽑기!
// 9C7 == 9C2 이므로 2개만 뽑아도 됨
#include <bits/stdc++.h>
using namespace std;
int a[9];
int sum=0;
vector<int> v;
pair<int, int> ret;
void solve(){
    // 2개를 뽑아야 하므로 2중 for문
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < i; j++){
            if(sum -a[i] - a[j] == 100){
                // 100이 될 때의 A,B 2개를 ret에 저장 
                ret = {i, j};
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 전체합 구하기
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }
    solve(); // 2개 뽑기
    for(int i = 0; i < 9; i ++){
        // 여기 부분 이해 안됨!
        // ret.first와 ret.second에는 제외할 2명의 인덱스가 저장되어 있음
        // 현재 인덱스 i가 제외할 2명 중 하나라면 continue로 건너뜀
        // 즉, 제외할 2명은 벡터에 넣지 않고, 나머지 7명만 벡터에 저장
        if(ret.first == i || ret.second == i) continue;
        v.push_back(a[i]);
    }
    // 오름차순 술력
    sort(v.begin(), v.end());
    for(int i : v) cout << i << "\n";
    return 0;
}