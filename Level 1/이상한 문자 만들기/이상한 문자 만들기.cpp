#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);

string solution(string s) {
    
    string answer = "";
    
    // 문자열 s를 공백문자 기준으로 split
    vector<string> s_split = split(s, ' ');
    
    for (int i = 0; i < s_split.size(); i++) {
        
        string temp = s_split.at(i);
        
        for (int j = 0; j < temp.length(); j++) {
            
            if ((j % 2) == 0) {
                
                answer += toupper(temp.at(j));
            }
            
            else {
                
                answer += tolower(temp.at(j));
            }
        }
        
        if (i == (s_split.size() - 1)) break;
        
        answer += " ";
    }
    
    // 주어진 문자열 s의 맨 마지막이 공백으로 끝날 경우
    if (s.at(s.length() - 1) == ' ') {
        
        answer += " ";
    }
    
    return answer;
}

// String Split Function
vector<string> split(string input, char delimiter) {
    
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        
        answer.push_back(temp);
    }
 
    return answer;
}