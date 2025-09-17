#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[64][64];

string quard(int y, int x, int size){
    // return case 1 : 1개 쪼개질 때까지 다른 경우
    // string(1, char) 는 char를 string으로 만들기 위함
    if(size == 1) return string(1, a[y][x]);
    
    // 시작 값 (이후 값 비교를 위함)
    char b = a[y][x];
    string ret = "";
    bool flag = 0;
    // 현재 위치에서 size 영역 범위만큼 탐색
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            // return case 2 : size 영역 중 일부가 다른 경우 
            if(b != a[i][j]){
                ret += '(';
                // z자로 4분할 탐색 
                ret += quard(y, x, size/2);
                ret += quard(y, x + size/2, size/2);
                ret += quard(y + size/2, x, size/2);
                ret += quard(y + size/2, x + size/2, size/2);
                ret += ')';
                return ret;
            }
        }
    }
    // return case 3: size 영역이 모두 같은 숫자인 경우
    return string(1, a[y][x]); 
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j];
        }
    }
    cout << quard(0, 0, n) << "\n";
    return 0;
}