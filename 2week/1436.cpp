#include <bits/stdc++.h>
using namespace std;
int n, ret;
int main(){
    cin >> n;
    int i = 666;
    // 어떻게 n과 ret을 매핑하지?
    for(;;i++){
        // 숫자를 str화 하고 "666"찾기 (string::npos)조건은 못찾았을 때의 결과
        if(to_string(i).find("666") != string::npos)n--;
        if(n==0)break;
    }
    cout << i << "\n";
    return 0;
}