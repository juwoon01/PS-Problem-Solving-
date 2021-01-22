/*https://www.acmicpc.net/problem/10844*/
/*
동적계획법
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다.
이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오.
(0으로 시작하는 수는 없다.)
첫째 줄에 N이 주어진다.
N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

풀이
  1. 1 = 9
     2 = 10,12,21,23,32,34...87,89,98 = 9+9-1
     3 = 101, 121, 123, 210, 212, 232, 234...898, 987, 989 = 17 + 15?(10->101, 89 -> 898)
     4 = 1010, 1012, 1210, 1212, 2101, ... 32 + 29?

    1.1
      끝이 0과 9면 다음 숫자에 -1 ex) 10, 98 -> 101 , 989
      1에는 9가 1개
      2에는 10, 89
      3에는 210,789,989
      4에는 1010,1210,8989,6789

  2. 각 수는 N-1의 앞뒤 숫자들의 수
  ex) N = 3의 4의 수는 N = 2 의 5와 3의 수
  65 ,45 / 43, 23 -> 654, 454, 434, 234

  3. 상향식 DP

  규칙을 찾는 것은 역시 기본이고 중요하다.
  수가 높으면 long long을 쓰자
  결과에 나머지를 하라고 하면 결과에 직접적 영향이 있는 곳에도 나머지를 취해보자
*/

#include <iostream>
#include <math.h>
using namespace::std;
int main(void){
  int N;
  cin >> N;
  long long result = 0;
  long long num[100][10] ={{0,1,1,1,1,1,1,1,1,1},};

  for(int i=1;i<N;i++){

    for(int j=0;j<=9;j++){
      if(j == 0){
        num[i][j] = num[i-1][j+1] % 1000000000;
      }
      else if(j == 9){
        num[i][j] = num[i-1][j-1] % 1000000000;
      }
      else{
        num[i][j] = (num[i-1][j-1] + num[i-1][j+1]) % 1000000000;
      }
    }

  }

  for(int i=0;i<=9;i++){
    result += num[N-1][i];
  }
  cout << (result % 1000000000);

  return 0;
}