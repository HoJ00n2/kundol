#include <bits/stdc++.h>
using namespace std;
string s, ret;
int cnt[200], flag;
char mid;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    // 펠린드롬 알고리즘
    // 알파벳 해당 아스키 부분 카운팅
    for(char a : s)cnt[a]++;
    // 아스키 숫자 높은것부터 채우기 (오름차순 출력이므로)
    for(int i = 'Z'; i >= 'A'; i--){
        if(cnt[i]){
            // 홀수인지 짝수인지 체크하는 방법 => & 1 (홀수!)
            if(cnt[i] & 1){ 
                mid = char(i);
                flag++;
                cnt[i]--;
            }
            // 홀수가 2개 => 안되는 경우
            if(flag == 2)break;
            // ret 앞뒤로 문자붙이기
            // BBCCC 라면 -> ret=CCC 인상황에서 B(ret)B 붙이기
            // 앞, 뒤로 문자를 붙였으니 2개 빠지고 j는 2개씩 증가
            for(int j = 0; j < cnt[i]; j += 2){
                ret = char(i) + ret; // 뒤에 붙이기
                ret += char(i); // 앞에 붙이기
            }
        }
    }
    // 홀수 알파벳이 1개인 경우 => ret 중간에 삽입
    if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag==2)cout << "I'm Sorry Hansoo" << "\n";
    else cout << ret << "\n";
    return 0;
}