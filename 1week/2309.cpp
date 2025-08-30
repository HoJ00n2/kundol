#include <bits/stdc++.h>  // 모든 표준 라이브러리를 포함하는 헤더 (경쟁 프로그래밍용)
using namespace std;      // std 네임스페이스 사용 선언
int a[9];                 // 9개의 정수를 저장할 전역 배열 선언

int main(){
   ios_base::sync_with_stdio(false);  // C와 C++의 입출력 동기화 해제 (속도 향상)
   cin.tie(NULL);                     // cin과 cout의 연결 해제 (속도 향상)
   cout.tie(NULL);                    // cout 버퍼 해제 (속도 향상)
   
   for(int i = 0; i < 9; i++){        // 0부터 8까지 9번 반복
       cin >> a[i];                   // 배열 a[i]에 입력값 저장
   }
   
   sort(a, a + 9);                    // 배열 a를 오름차순으로 정렬
   
   do{                                // do-while 루프 시작
       int sum = 0;                   // 합계를 저장할 변수를 0으로 초기화
       for(int i = 0; i < 7; i++) sum += a[i];  // 배열의 첫 7개 원소의 합 계산
       if(sum == 100) break;          // 합이 100이면 루프 탈출
       
   }while(next_permutation(a, a + 9)); // 배열의 다음 순열을 생성, 더 이상 순열이 없으면 false 반환

   for(int i = 0; i < 7; i++) cout << a[i] << "\n";  // 조건을 만족하는 첫 7개 원소를 각각 새 줄에 출력

   return 0;                          // 프로그램 정상 종료
}