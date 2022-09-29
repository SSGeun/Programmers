#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution (string s) {
    
    int answer = 0;
    stack<char> s_stack;
    
    for (int i = 0; i < (s.length() - i); i++) {
        
        bool correct = true;
        
        for (int j = i; j < s.length(); j++) {
            
            if ((s.at(j) == '(') || (s.at(j) == '{') || (s.at(j) == '[')) {
                
                s_stack.push(s.at(j));
            }
            
            else if (s.at(j) == ')') {
                
                if (s_stack.empty()) {
                    
                    correct = false;
                    break;
                }
                
                if (s_stack.top() == '(') {
                    
                    s_stack.pop();
                }
                
                else {
                    
                    correct = false;
                    break;
                }
            }
            
            else if (s.at(j) == '}') {
                
                if (s_stack.empty()) {
                    
                    correct = false;
                    break;
                }
                
                if (s_stack.top() == '{') {
                    
                    s_stack.pop();
                }
                
                else {
                    
                    correct = false;
                    break;
                }
            }
            
            else if (s.at(j) == ']') {
                
                if (s_stack.empty()) {
                    
                    correct = false;
                    break;
                }
                
                if (s_stack.top() == '[') {
                    
                    s_stack.pop();
                }
                
                else {
                    
                    correct = false;
                    break;
                }
            }
        }
        
        // 올바른 괄호일 경우 (스택이 비어있고, correct가 참일 경우)
        if (s_stack.empty() && correct) {
            
            answer += 1;
        }
        
        // 괄호 문자열 s 회전
        s += s.at(i);
        
        // 스택 초기화
        while (!s_stack.empty()) {
            
            s_stack.pop();
        }
    }
    
    return answer;
}