#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    string answer = "";
    
    int center = 0;
    
    // 단어 s의 길이가 홀수인 경우
    if (s.length() % 2 == 1) {
        
        center = (s.length() + 1) / 2;
        
        answer += s.at(center - 1);
    }
    
    // 단어 s의 길이가 짝수인 경우
    else {
        
        center = s.length() / 2;
        
        answer += s.at(center - 1);
        answer += s.at(center);
    }
    
    return answer;
}