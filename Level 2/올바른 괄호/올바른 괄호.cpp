/*
    풀이법
    1. 여는 괄호 '('를 담을 stack 선언
    2. 주어진 문자열 s의 각 인덱스를 순회하며 여는 괄호 '('일 시 push
    3. 닫는 괄호 ')'일 시 pop
       (단, 스택이 비어 있다면 false)
    4. 주어진 문자열 s를 전부 순회한 뒤 스택에 요소가 남아있으면 false
*/

#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    
    bool answer = true;

    stack<char> parenthesis;
    
    for (int i = 0; i < s.length(); i++) {
        
        if (s.at(i) == '(') {
            
            parenthesis.push('(');
        }
        
        else if (s.at(i) == ')') {
            
            if (parenthesis.empty()) {
                
                answer = false;
                break;
            }
            
            parenthesis.pop();
        }
    }
    
    if (!parenthesis.empty()) {
        
        answer = false;
    }

    return answer;
}