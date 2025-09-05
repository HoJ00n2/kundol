#include <bits/stdc++.h>
using namespace std;
string s, temp;
bool result;
int main(){
    // 단어 입력
    cin >> s;
    temp = s;
    // 뒤집은 단어, reverse는 원본이 수정되므로 temp를 선언!
    reverse(temp.begin(), temp.end());
    // 앞뒤로 같은지 체크 (배열이면 reverse와 비교)
    if (s == temp) result=1;
    // 정답 출력
    cout << result << "\n";
    return 0;
}