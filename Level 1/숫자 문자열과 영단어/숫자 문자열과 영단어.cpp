/*
    풀이법
    1. 주어진 문자열 s의 길이만큼 반복문을 수행하면서 '숫자인 경우'와 '영단어인 경우'를 구분한다.
    2. 숫자인 경우 그대로 활용
    3. 영단어인 경우 빈 문자열에 한 자리씩 추가하며 길이가 3 이상이 될 때까지 반복 수행한다.
    4. 영단어의 길이가 3 이상이 되었을 때, 해당 영단어를 숫자로 변환할 수 있는지 확인한다.
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int answer = 0;
    string s_answer = "";
    
    for (int i = 0; i < s.length(); i++) {
        
        // 숫자인 경우
        if (s.at(i) >= '0' && s.at(i) <= '9') {
            
            s_answer += s.at(i);
        }
        
        // 영단어인 경우
        else {
            
            string temp = "";
            
            for (int j = i; j < s.length(); j++) {
                
                temp += s.at(j);
                
                // 영단어의 최소 길이가 3이므로 그 이하는 continue
                if (temp.length() < 3) {
                    
                    continue;
                }
                
                // 영단어의 길이가 3인 경우
                else if (temp.length() == 3) {
                    
                    if (temp == "one") {
                        
                        s_answer += '1';
                    }
                    
                    else if (temp == "two") {
                        
                        s_answer += '2';
                    }
                    
                    else if (temp == "six") {
                        
                        s_answer += '6';
                    }
                }
                
                // 영단어의 길이가 4인 경우
                else if (temp.length() == 4) {
                    
                    if (temp == "zero") {
                        
                        s_answer += '0';
                    }
                    
                    else if (temp == "four") {
                        
                        s_answer += '4';
                    }
                    
                    else if (temp == "five") {
                        
                        s_answer += '5';
                    }
                    
                    else if (temp == "nine") {
                        
                        s_answer += '9';
                    }
                }
                
                // 영단어의 길이가 5인 경우
                else if (temp.length() == 5) {
                    
                    if (temp == "three") {
                        
                        s_answer += '3';
                    }
                    
                    else if (temp == "seven") {
                        
                        s_answer += '7';
                    }
                    
                    else if (temp == "eight") {
                        
                        s_answer += '8';
                    }
                }
            }
        }
    }
    
    answer += stoi(s_answer);
    
    return answer;
}