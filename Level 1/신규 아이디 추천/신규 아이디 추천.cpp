#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    
    string answer = "";
    
    // 1단계. 모든 대문자를 소문자로 변환
    for (int i = 0; i < new_id.length(); i++) {
        
        if (new_id.at(i) >= 'A' && new_id.at(i) <= 'Z') {
            
            new_id.at(i) += 32;
        }
    }
    
    // 2단계. 소문자, 숫자, -, _, . 제외한 문자 제거
    for (int i = 0; i < new_id.length(); i++) {
        
        if (new_id.at(i) >= 'a' && new_id.at(i) <= 'z') {
            
            continue;
        }
        
        else if (new_id.at(i) >= '0' && new_id.at(i) <= '9') {
            
            continue;
        }
        
        else if (new_id.at(i) != '-' && new_id.at(i) != '_' && new_id.at(i) != '.') {
            
            // 해당 문자를 지움으로써 한 글자씩 앞으로 당겨지므로 i를 1 줄여준다.
            new_id.erase(i, 1);
            i--;
        }
    }
    
    // 3단계. 마침표가 연속해서 등장하면 하나만 출력
    // 4단계. 마침표가 처음과 끝에 위치하면 제거
    for (int i = 0; i < new_id.length(); i++) {
        
        if (new_id.at(i) == '.') {
            
            if (i == 0 || i == (new_id.length() - 1)) {
                
                new_id.erase(i, 1);
                i--;
                continue;
            }
            
            if (new_id.at(i + 1) == '.') {
                
                // 해당 문자를 지움으로써 한 글자씩 앞으로 당겨지므로 i를 1 줄여준다.
                new_id.erase(i, 1);
                i--;
            }
        }
    }
    
    // 5단계. 문자열이 비어있으면 a 대입
    if (new_id.length() == 0) {
        
        new_id += 'a';
    }
    
    // 6단계. 문자열의 길이가 16이상일 시 첫 15개 제외 나머지 제거
    else if (new_id.length() >= 16) {
        
        new_id.erase(15, new_id.length() - 15);
        
        // 6단계. 문자열 길이 줄인 후, 마지막이 마침표면 제거
        if (new_id.at(14) == '.') {
            
            new_id.erase(14, 1);
        }
    }
    
    // 7단계. 문자열의 길이가 2이하일 경우, 길이가 3이 될 때까지 마지막 문자 반복
    if (new_id.length() <= 2) {
        
        char c_char = new_id.at(new_id.length() - 1);
        
        while (new_id.length() != 3) {
            
            new_id += c_char;
        }
    }
    
    answer = new_id;
    
    return answer;
}