#include <bits/stdc++.h>
using namespace std;
string s;
int lcnt, vcnt; // 모음, 자음 연속 개수
// 모음 판별
bool isVowel(int idx){
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main(){

    while(cin >> s){
        if(s == "end")break;
        lcnt = vcnt = 0;
        bool flag = 0;
        bool is_include_v = 0; // 모음이 있는가?
        int prev = -1;
        for(int i = 0; i < s.size(); i++){
            int idx = s[i];
            // 1단계 모음이 1개라도 있나?
            if(isVowel(idx))lcnt++, vcnt = 0, is_include_v = 1;
            else vcnt++, lcnt = 0;
            // 2단계 연속 모음,자음이 3개있는가?
            if(vcnt == 3 || lcnt == 3) flag = 1;
            // 3단계 o, e 제외 같은 글자가 연속으로 2개 오나?
            if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){
                flag = 1;
            }
            prev = idx;
        }
        if(is_include_v == 0) flag = 1;
        if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
        else cout << "<" << s << ">" << " is acceptable.\n";
    }
    return 0;
}