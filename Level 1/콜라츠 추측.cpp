#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    
    int answer = 0;
    
    while (num != 1) {
        
        // 500번 반복 시 -1 반환
        if (answer == 500) {
            
            answer = -1;
            break;
        }
        
        // 입력된 수가 짝수라면 2로 나눈다.
        if ((num % 2) == 0) {
            
            num /= 2;
        }
        
        // 입력된 수가 홀수라면 3을 곱하고 1을 더한다.
        else if ((num % 2) == 1) {
            
            num *= 3;
            num += 1;
        }
        
        answer++;
    }
    
    return answer;
}