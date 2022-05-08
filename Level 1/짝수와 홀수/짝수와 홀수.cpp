#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    
    string answer = "";
    
    // num이 0이거나 짝수인 경우
    if ((num == 0) || ((num % 2) == 0)) {
        
        answer = "Even";
    }
    
    // num이 홀수인 경우
    else {
        
        answer = "Odd";
    }
    
    return answer;
}