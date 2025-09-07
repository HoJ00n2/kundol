#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;
string a[100004];

int main(){
    // 시간관리 빡세기 때문에 이 조건 넣어주기
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    // 도감 저장
    for(int i = 0; i < n; i++){
        cin >> s;
        mp[s] = i + 1; // 포켓몬 도감 저장 (str : int)
        mp2[i+1] = s; // 포켓몬 도감2 저장 (int : str)
        a[i + 1] = s; // 포켓몬 도감 배열에 저장, mp2와 비교를 위함
    }
    // 문제 제공
    for(int i = 0; i < m; i++){
        cin >> s;
        // 문제가 문자라면
        if(atoi(s.c_str())==0){
            cout << mp[s] << "\n";
        }
        // 문제가 숫자라면 
        else{
            // index주고 배열탐색 -> O(1)
            cout << a[atoi(s.c_str())] << "\n";
            // 숫자값주고 map 탐색 -> 똑같이 O(logN)
            // cout << mp2[atoi(s.c_str())] << "\n";
        }
    }
}