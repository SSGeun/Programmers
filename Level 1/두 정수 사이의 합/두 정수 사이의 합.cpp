#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    
    long long answer = 0;
    
    // 두 수가 같은 경우
    if (a == b) {
        
        answer = a;
    }
    
    // 두 수가 다른 경우
    else {
        
        // a < b로 변환
        if (a > b) {
            
            int temp = a;
            a = b;
            b = temp;
        }
        
        for (int i = a; i <= b; i++) {
            
            answer += i;
        }
    }
    
    return answer;
}