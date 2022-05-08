#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    
    long long answer = 0;
    
    // n의 제곱근 값 구하기
    double result = sqrt(n);
    
    // 강제 형 변환을 통해 n의 제곱근 값이 정수인지 확인
    if ((result - (int)result) == 0) {
        
        answer = pow(result + 1, 2);
    }
    
    else {
        
        answer = -1;
    }
    
    return answer;
}