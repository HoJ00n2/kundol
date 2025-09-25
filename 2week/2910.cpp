#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;
// cmp 입력으로 v.begin() ~ v.end()까지의 요소들이며 비교군 둘 다 pair<int, int> 형태 
bool cmp(pair<int, int> a, pair<int ,int> b){
    // 빈도수 같다면 >> 먼저 나온거 반환
    if(a.first == b.first){
        // 아래가 성립하면 1반환 아니면 0 반환
        // mp_first[] 값이 작은 것 = 먼저 입력된 index 순으로 반환
        // 먼저 입력된 순으로 오름차순
        return mp_first[a.second] < mp_first[b.second];
    }
    // 조건 성립하면 1 반환 아니면 0 반환
    // 카운트 많은 순으로 내림 차순
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        // 왜 굳이 배열로 입력받지? 그냥 cin >> k; 하면 안되나?
        cin >> a[i];
        mp[a[i]]++;
        // 해당 key 값이 없다면, 해당 key가 처음 나온 index 넣기 
        // i를 할당하면 0이 넣어져 로직 문제가 생기므로 i + 1
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
    }
    // map 정렬 안되므로 vector에 넣어줌
    for(auto it : mp){
        v.push_back({it.second, it.first});
    }
    // 커스텀 정렬 (벡터 시작 위치, 벡터 끝 위치, 정렬 기준)
    // 정렬 기준 == 파이썬의 lambda
    // 이때 각 v의 요소들은 pair<int, int> 형태 begin ~ end 둘 다
    sort(v.begin(), v.end(), cmp);
    // 정렬된 벡터에서
    for(auto i : v){
        // 빈도 개수만큼 입력값 출력 (it.second, it.first)를 vector에 넣었으므로
        for(int j = 0; j < i.first; j++){
            cout << i.second << " ";
        }
    }
    return 0;
}