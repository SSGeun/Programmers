/*
    풀이법
    - n * n 2차원 배열 전체를 구성하려고 하면 시간 초과 나옵니다.
    - 구하고자 하는 값은 left에서 right까지 이므로 이를 활용하면 전체 배열을 구하지 않고 답을 유추할 수 있습니다.
      (행(row)는 i / n, 열(column)은 i % n)
    - 이때 행, 열 중 더 큰 값 + 1이 해당 인덱스의 값입니다.
    
    ** 반복문 내 i의 자료형을 int형으로 할 시 시간초과 나옵니다.
        (함수의 left, right의 자료형이 long long이므로 이를 사용하는 반복문 내 i의 자료형은 long long으로 해줍니다.)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        
        int row = (i / n);
        int column = (i % n);
        
        int result = ((row >= column) ? (row + 1) : (column + 1));
        
        answer.push_back(result);
    }
    
    return answer;    
}