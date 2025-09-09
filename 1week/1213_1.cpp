#include <bits/stdc++.h>
using namespace std;
char mid;
int cnt[200];
string s, ret;
int flag;
int main(){
    // 입력
    cin >> s;
    // 각 글자들 카운트
    for(char c : s)cnt[c]++;
    // 내림차순으로 짝수개만 채워넣기
    for(char c='Z'; c >='A'; c--){
        // 입력한 알파벳중에서
        if(cnt[c]){
            // 카운팅된 개수가 홀수개면
            if(cnt[c] & 1){
                mid = c; // 가장 마지막 중간에 넣을 단어 
                flag++;
                cnt[c]--; //일단 짝수개만 넣을거라
            }
        }
        // 홀수 알파벳인 경우가 2개 이상이면
        if(flag==2) break;
        // 알파벳 짝수개만 채워넣기
        for(int i = 0; i < cnt[c]; i+=2){
            ret = c + ret; // 앞에 붙이기
            ret += c; // 뒤에 붙이기
        }
    }
    // 만약 홀수개인게 있다면 가운데 넣기
    // ret.end가 아닌 ret.size인 이유
    // 일단 insert의 첫번째 args는 iterator type이 와야함
    // 이때 begin, end는 iterator type이며, size는 정수
    // iterator는 포인터라 생각하면 됨 특정 위치를 가리킴 (idx)
    // iterator + 정수 = iterator이며, iterator 위치 + 정수만큼의 위치
    // 즉, begin = 0을 가리키며, + 정수 했으므로 정수 idx를 가리키는 이터레이터
    // 결론적으로, ret.begin() + ret.size() / 2는 중간 위치를 가리키는 iterator
    if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
    // 펜린드롬 되면 출력, 안되면 다른 답 출력
    if(flag==2)cout << "I'm Sorry Hansoo" << "\n";
    else cout << ret << "\n";
    return 0;
}