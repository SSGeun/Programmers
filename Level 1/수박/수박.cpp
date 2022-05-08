#include <string>
#include <vector>

using namespace std;

// 삼항 연산자 사용
/*
string solution(int n) {
    
    string answer = "";
    
    for (int i = 0; i < n; i++) {
        
        answer += (i % 2 == 0) ? "수" : "박";
    }
    
    return answer;
}
*/

// 일반적인 조건문 사용
string solution(int n) {
    
    string answer = "";
    
    for (int i = 0; i < n; i++) {
        
        if ((i % 2) == 0) {
            
            answer += "수";
        }
        
        else {
            
            answer += "박";
        }
    }
    
    return answer;
}