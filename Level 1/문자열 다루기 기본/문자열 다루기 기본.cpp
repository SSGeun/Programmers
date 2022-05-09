#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    bool answer = true;
    
    // 문자열 s의 길이가 4 혹은 6인지 확인
    if (s.length() == 4 || s.length() == 6) {
        
        for (int i = 0; i < s.length(); i++) {
            
            if (s.at(i) < '0' || s.at(i) > '9') {
                
                answer = false;
                break;
            }
        }
    }
    
    else {
        
        answer = false;
    }
    
    return answer;
}