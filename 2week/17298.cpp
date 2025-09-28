#include <bits/stdc++.h>
using namespace std;
int n, a[1000004], ret[1000004];
stack<int> st;
int main(){
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        // 오큰수 못만난 애들이 담긴 상태에서 오큰수를 만났다면
        while(st.size() && a[st.top()] < a[i]){
            // 오큰수보다 작은 요소들만 ret에 오큰수 저장하고 pop
            ret[st.top()] = a[i]; st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++) cout << ret[i] << " ";
    return 0;
}