#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        stack<char> st;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ')' && !st.empty() && st.top() == '(')st.pop();
            else st.push(s[j]);
        }
        if(st.empty())cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}