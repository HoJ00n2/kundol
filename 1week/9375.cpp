#include <bits/stdc++.h>
using namespace std;
string a, b;
int t, n;
map<string, string> mp; // <가진 의상, 의상 종류>
int main(){
    cin >> t;
    while(t--){
        // 테케마다 초기화 되므로 이때 선언
        map<string, int> _map;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            // 딱히 가진옷 이름 필요 없으므로 종류만 cnt+1
            _map[b]++;
        }
        // 결과 저장용 변수 (곱셈이라 1로)
        // 경우의 수 담을 변수는 long long 선언하는게 tip
        long long ret = 1;
        // 경우의 수 구하기
        for(auto c: _map){
            ret *= ((long long)c.second + 1);
        }
        // 모두 선택안한 경우의수 1 빼기
        ret--;
        cout << ret << "\n";
    }

    return 0;
}