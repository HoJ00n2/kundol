#include <bits/stdc++.h>
using namespace std;
int a;
string pattern, s, pre, suf;
int main(){
    cin >> a;
    cin >> pattern;
    // 패턴의 * index 찾기
    int pos = pattern.find('*');
    // * 패턴 접두사 접미사 찾기
    pre = pattern.substr(0, pos);
    suf = pattern.substr(pos + 1);

    for(int i = 0; i < a; i++){
        cin >> s;
        // 접두사 접미사와 s 비교
        if(s.size() < pre.size() + suf.size()) cout << "NE\n";
        else{
            if(pre == s.substr(0, pos) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }        
    }

    return 0;
}