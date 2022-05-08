#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    
    string answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        
        // 공백이 입력된 경우 그대로 공백 출력
        if (s.at(i) == ' ') {
            
            answer += s.at(i);
            continue;
        }
        
        // 주어진 알파벳이 대문자인 경우
        if (s.at(i) >= 65 && s.at(i) <= 90) {
            
            // 주어진 정수 n만큼 밀어냈을 때 Z를 넘어가는 경우
            if ((s.at(i) + n) > 90) {
                
                answer += (s.at(i) - 26 + n);
            }
            
            else {
                
                answer += (s.at(i) + n);
            }
        }
        
        // 주어진 알파벳이 소문자인 경우
        else if (s.at(i) >= 97 && s.at(i) <= 122) {
            
            // 주어진 정수 n만큼 밀어냈을 때 z를 넘어가는 경우
            if ((s.at(i) + n) > 122) {
                
                answer += (s.at(i) - 26 + n);
            }
            
            else {
                
                answer += (s.at(i) + n);
            }
        }
    }
    
    return answer;
}