#include <bits/stdc++.h>
using namespace std;
int n, cnt[26]; // 알파벳 개수만 저장할 배열
string s, result;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[s[0] - 'a']++;
    }
    // 개수 세기
    for(int i = 0; i < 26; i++){
        if(cnt[i] >= 5) result += i + 'a';
    }
    // 아스키 코드에 의해 알파벳 순으로 세기 때문에 정렬할 필요 x
    if(result.size()) cout << result << "\n";
    else cout << "PREDAJA" << "\n";
    return 0;
}