#include <string>
#include <vector>

using namespace std;

// 약수 구하는 방법 1
/*
int solution(int n) {
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        
        if (n % i == 0) {
            
            answer += i;
        }
    }
    
    return answer;
}
*/

// 약수 구하는 방법 2
/*
int solution(int n) {
    
    int answer = 0;
    
    for (int i = 1; i <= (n / 2); i++) {
        
        if (n % i == 0) {
            
            answer += i;
        }
    }
    
    answer += n;
    
    return answer;
}
*/

// 약수 구하는 방법 3
int solution(int n) {
    
    int answer = 0;
    
    for (int i = 1; (i * i) <= n; i++) {
        
        if ((i * i) == n) {
            
            answer += i;
            break;
        }
        
        if (n % i == 0) {
            
            answer += i;
            
            answer += (n / i);
        }
    }
    
    return answer;
}