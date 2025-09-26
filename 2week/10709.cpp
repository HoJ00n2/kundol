#include <bits/stdc++.h>
using namespace std;
int h, w, cnt;
string s;
char c[101][101];
int a[101][101];
int main(){
    // 출력배열 -1로 초기화
    memset(a, -1, sizeof(a));
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> s;
        // 입력배열 입력
        for(int j = 0; j < s.size(); j++){
            c[i][j] = s[j];
            // 구름 초기 위치 0
            if(s[j]=='c')a[i][j] = 0;
        }
    }
    // 각행의 가장 왼쪽의 c보다 왼쪽영역은 -1 >> 애초 초기화 -1이라 의미없음
    // 이동한 애들만 채워주면 됨
    while(cnt!=w){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w-1; j++){
                // 현재 -1이 아니고 다음칸이 0이 아니라면
                if(a[i][j] != -1 && a[i][j+1] != 0)a[i][j+1] = a[i][j]+1;
            }
        }
        cnt++;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}