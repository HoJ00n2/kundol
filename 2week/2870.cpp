#include <bits/stdc++.h>
using namespace std;
int m;
vector<string> ret;
string s, num;
void go(){
    while(true){
        // 맨앞이 0으로 시작할 때 0 지우는 로직
        // 항상 front, top 체크할 때는 size가 존재하는지 같이 체크!
        if(num.size() && num.front() == '0')num.erase(num.begin());
        // 다 없앴거나 맨 앞이 0아닌 숫자만 남았다면 break
        else break;
    }
    // 000인 경우 -> 0이 되어야
    if(num.size() == 0) num = "0";
    ret.push_back(num);
    num = "";
}
bool cmp(string a, string b){
    // 2순위 비교 (사이즈가 같다면 앞에서부터 문자열 아스키 비교)
    if(a.size() == b.size()) return a < b;
    // 1순위 비교 (숫자 길이 비교)
    return a.size() < b.size();
}
int main(){
    cin >> m;
    while(m){
        num = "";
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            // s[i]가 문자인지 숫자인지 판단
            if(s[i] < 65)num += s[i];
            // s[i]는 문자인데 숫자가 채워진 경우 벡터에 담기
            else if(num.size()) go();
        }
        if(num.size()) go();
        m--;
    }
    // ret에 담긴것은 string이고 아스키코드 순으로 정렬되므로 cmp 필요
    sort(ret.begin(), ret.end(), cmp);
    for(string ss : ret){
        cout << ss << "\n";
    }
    return 0;
}