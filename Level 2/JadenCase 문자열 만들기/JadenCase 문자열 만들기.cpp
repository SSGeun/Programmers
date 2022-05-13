/*
    풀이법
    1. 주어진 문자열 s의 알파벳을 전부 소문자로 변환한다.
    2. s의 길이만큼 반복문을 수행하며 공백 뒤의 소문자를 대문자로 변환한다.
    3. 2번 과정에서 문자열 시작점이 체크되지 않으므로 문자열 첫 시작이 소문자일 경우 대문자로 변환한다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    string answer = "";
    
    // 주어진 문자열 s의 대문자를 소문자로 변환
    for (int i = 0; i < s.length(); i++) {
        
        if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
            
            s.at(i) += 32;
        }
    }
    
    // 문자열 s의 길이만큼 반복문을 수행하며 공백 뒤에 소문자 알파벳을 대문자로 변환
    for (int i = 0; i < (s.length() - 1); i++) {
        
        if (s.at(i) == ' ') {
            
            if (s.at(i + 1) >= 'a' && s.at(i + 1) <= 'z') {
                
                s.at(i + 1) -= 32;
            }
        }
    }
    
    // 문자열의 시작이 소문자 알파벳이면 대문자로 변환
    if (s.at(0) >= 'a' && s.at(0) <= 'z') {
        
        s.at(0) -= 32;
    }
    
    answer = s;
    
    return answer;
}