#include <bits/stdc++.h>
using namespace std;
string s;
char cc;
int n, ret;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        // A나 B가 홀수개면 넘어가기 (좋은단어 x)
        // 연속하면 pop하고 나머지에서 또 찾기 반복 >> stack이네 ..
        stack<char> stk;
        for(char a: s){
            // stack이 있는 상태이며, top과 들어올 문자가 같다면 pop
            if(stk.size() && stk.top() == a)stk.pop();
            else stk.push(a);
        }
        // stack 다 pop 됐다면 -> 좋은 단어
        if(stk.size() == 0)ret++;
    }
    cout << ret << "\n";
    return 0;
}