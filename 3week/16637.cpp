#include <bits/stdc++.h>
using namespace std;
vector<int> num; // 숫자만 담을 벡터
vector<char> oper_str;  // 연산자 담을 벡터
int n, ret = -987654321;
string s;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
int oper(char a, int b, int c){
    if(a == '+') return b + c;
    if(a == '-') return b - c;
    if(a == '*') return b * c;
}
void go(int here, int _num){
    // 디버그 확인용 코드
    // cout << here << " : " << _num << "\n";
    // 기저 사례 : 모든 숫자를 다 돌았다면
    if(here == num.size() - 1){
        ret = max(ret, _num);
        return; 
    }
    // 다음 idx 넘어가서 비교, 2가지 경우로
    // _num은 현재 idx 누적합을 의미
    // 현재 idx는 0이며, 3 x 8 + 5 를 예시로 들면 ..
    // case 1
    // 3 x 8을 먼저 하고 + 5를 함
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    // case 2
    // 8 + 5를 먼저 하고 x 3을 함
    if(here + 2 <= num.size() - 1){
        // 8 + 5로 뒤에 먼저 계산하는 과정 
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        // x 3
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}

int main(){
    fastIO();
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        // 짝수 idx는 숫자 벡터에 삽입 (숫자로 삽입)
        if(i % 2 == 0)num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    }
    // 초기값 정보 주며 시작 (초기값 idx, 초기값 value)
    go(0, num[0]);
    cout << ret << "\n";
    return 0;
}