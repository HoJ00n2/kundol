#include <bits/stdc++.h>
using namespace std;
int a;
map<char, int> m;
string s, result;
int main(){
    // 예제 입력
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> s;
        // 성 첫글자만 map에 추가
        m[s[0]]++;
    }

    // map 순회하면서 value가 5 넘나 확인
    // map.first -> key, map.second -> value
    for(auto& pair : m){
        if(pair.second >= 5) result+=pair.first;
    }
    // result가 비지 않았다면 정렬 후 출력
    if(!result.empty()) {
        sort(result.begin(), result.end());
        cout << result << "\n";
    }
    else cout << "PREDAJA" << "\n";
    return 0;
}