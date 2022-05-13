/*
    풀이법
    1. 주어진 문자열 s를 공백 기준으로 split
    2. split한 결과에서 최솟값과 최댓값을 찾아 answer에 할당
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split(string input, char delimiter);

string solution(string s) {
    
    string answer = "";
    
    vector<int> s_split = split(s, ' ');
    
    int max_num = s_split.at(0);
    int min_num = s_split.at(0);
    
    for (int i = 1; i < s_split.size(); i++) {
        
        if (s_split.at(i) > max_num) {
            
            max_num = s_split.at(i);
        }
        
        else if (s_split.at(i) < min_num) {
            
            min_num = s_split.at(i);
        }
    }
    
    answer += to_string(min_num);
    answer += " ";
    answer += to_string(max_num);
    
    return answer;
}

vector<int> split(string input, char delimiter) {
    
    vector<int> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        
        answer.push_back(stoi(temp));
    }
 
    return answer;
}