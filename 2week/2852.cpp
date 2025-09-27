#include <bits/stdc++.h>
#define prev jj // prev라는 변수가 사전에 있으므로 따로 명시
using namespace std;
int n, o, A, B, asum, bsum;
string s, prev;
string print(int a){
    // 분 계산 90초를 예로들면 90/60 -> 1분
    // 00 더하는 이유는 1분을 01분으로 표현하기 때문, 이후 뒤에서 슬라이싱
    string d = "00" + to_string(a / 60);
    // 초 계산 90%60 -> 30초
    string e = "00" + to_string(a % 60);
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}
int changeToInt(string a){
    // 시간을 초단위로 변환 (int)
    // substr(시작위치, 크기)
    return atoi(a.substr(0,2).c_str()) * 60 + atoi(a.substr(3,2).c_str());
}
void go(int &sum, string s){
    sum += (changeToInt(s) - changeToInt(prev));
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> o >> s;
        if(A > B)go(asum, s);
        else if(B > A)go(bsum, s);
        // 입력한 팀에 점수 ++
        o == 1 ? A++ : B++;
        prev = s;
    }
    // 끝점 처리
    if(A > B)go(asum, "48:00");
    else if(B > A)go(bsum, "48:00");
    // 이긴 시간 분:초로 표현해야하므로 다시 역변환 
    cout << print(asum) << "\n";
    cout << print(bsum) << "\n";

}