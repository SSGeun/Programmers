/*
    풀이법
    1. 주어진 문자열 s의 각 자리를 반복하며 스택에 push
    2. 스택의 top 요소와 문자열 s의 다음 요소가 같으면 pop
    3. 1, 2번 과정을 문자열 s의 길이만큼 반복한 후 스택이 비어있으면 1, 스택에 요소가 존재하면 0
*/

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    
    int answer = -1;

    stack<char> result;
    
    for (int i = 0; i < s.length(); i++) {
        
        if (result.empty()) {
            
            result.push(s.at(i));
        }
        
        else {
            
            if (result.top() == s.at(i)) {
                
                result.pop();
                continue;
            }
            
            else {
                
                result.push(s.at(i));
            }
        }
    }
    
    answer = (result.empty() ? 1 : 0);
    
    return answer;
}