#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
	vector<int> answer;
    
    // answer 초기화
    for (int i = 0; i < id_list.size(); i++) {
        
        answer.push_back(0);
    }
    
    bool result[1001][1001] = { false };
    
    for (int i = 0; i < report.size(); i++) {
        
        int user_id;
        int report_id;
        
        vector<string> report_split = split(report.at(i), ' ');
        
        for (int j = 0; j < id_list.size(); j++) {
            
            if (id_list.at(j) == report_split.at(0)) {
                
                user_id = j;
                break;
            }
        }
        
        for (int k = 0; k < id_list.size(); k++) {
            
            if (id_list.at(k) == report_split.at(1)) {
                
                report_id = k;
                break;
            }
        }
        
        result[user_id][report_id] = true;
    }
    
    // 정지 기준이 되는 신고 횟수 k 확인
    for (int i = 0; i < id_list.size(); i++) {
        
        int count = 0;
        
        vector<int> temp;
        temp.clear();
        temp.assign(answer.begin(), answer.end());
        
        for (int j = 0; j < id_list.size(); j++) {
            
            if (result[j][i] == true) {
                
                answer.at(j) += 1;
                
                count++;
            } 
        }
        
        if (count < k) {
            
            answer.clear();
            answer.assign(temp.begin(), temp.end());
        }
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