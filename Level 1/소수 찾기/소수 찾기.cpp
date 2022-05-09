#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    
    // 인덱스 0과 1은 사용하지 않는다.
    bool PrimeArray[n + 1];
    
    // 초기에는 모든 수를 소수로 보고 true 값 할당
    for (int i = 2; i <= n; i++){
        
        PrimeArray[i] = true;
    }
    
    for (int i = 2; (i * i) <= n; i++) {
        
        if (PrimeArray[i]) {
            
            for (int j = (i * i); j <= n; j += i) {
                
                PrimeArray[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; i++) {
        
        if (PrimeArray[i]) {
            
            answer++;
        }
    }
    
    return answer;
}