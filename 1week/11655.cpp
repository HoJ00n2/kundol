#include <bits/stdc++.h>
using namespace std;

string s;
// 아스키코드 차이를 이용, 출력해보니 13차이
int main(){
    // 공백포함 문자 받기 -> s에 저장
    getline(cin, s);

    // 문자만 아스키 코드 차이로 변환하기
    for(char& c : s){
        if((65 <= c && c <= 77) || (97 <= c && c <= 109)){
            c = c + 13;
        }
        else if((78 <= c && c <= 90) || (110 <= c && c <= 132)){
            c = c - 13;
        }
    }
    cout << s << "\n";
    return 0;
}