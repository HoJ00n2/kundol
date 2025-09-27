#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    while(getline(cin, s)){
        stack<char> stk;
        if(s == ".")break;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[')stk.push(s[i]);
            else if(s[i] == ')'){
                if(!stk.empty() && stk.top() == '(')stk.pop();
                // 비었는데 넣을 경우
                else{
                    stk.push(s[i]);
                    break;
                } 
            } 
            else if(s[i] == ']'){
                if(!stk.empty() && stk.top() == '[')stk.pop();
                else{
                    stk.push(s[i]);
                    break;
                } 
            } 
        }
        if(stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}