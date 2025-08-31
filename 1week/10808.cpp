#include <bits/stdc++.h>
using namespace std;

// 전역변수로 초기화하면 숫자들은 0, 문자는 ""로 초기화됨!
int cnt[26];
string str ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;

    // 알파벳 개수 저장할 map(dict) or 배열 선언, 초기값 0
    // string loop 돌면서 채우기
    for(char a : str){
        // a는 아스키코드로 97인데, 이전 97개는 안쓰므로 - 'a'로 댕김
        // 소문자만 쓴댔으므로 
        cnt[a - 'a'] += 1;
    }
    for(int i = 0; i < 26; i++)cout << cnt[i] << " ";
   
    return 0;
}