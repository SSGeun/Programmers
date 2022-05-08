#include <string>
#include <iostream>

using namespace std;

long long solution(long long n) {
    
    long long answer = 0;
    
    // 각 Index 번호로 0-9 몇 번 등장했는지 확인
    int result[10] = { 0, };
    
    // answer 값 대입할 때 시작 점 확인
    bool start = true;
    
    // 0-9 등장 횟수 확인
    while (n != 0) {
        
        int index = n % 10;
        
        result[index]++;
        
        n /= 10;
    }
    
    // 9부터 나온 횟수만큼 출력
    for (int i = 9; i >= 0; i--) {
     
        if (result[i] != 0) {
            
            for (int j = 0; j < result[i]; j++) {

                if (start) {
                    
                    answer += i;
                    start = false;
                }
                
                else {
                    
                    answer *= 10;
                    answer += i;
                }
            }
        }
    }
    
    return answer;
}