#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    for (int i = 1; i < words.size(); i++) {
        
        // 이전 단어의 마지막 알파벳과 현재 단어의 첫 알파벳이 같은 경우
        if (words[i].at(0) == words[i - 1].at(words[i - 1].size() - 1)) {
            
            // 이전의 단어들과 중복되는 단어가 있는지 확인
            for (int j = 0; j < i; j++) {
                
                // 이전 단어와 현재 단어가 중복되는 경우
                if (words[j] == words[i]) {
                    
                    answer[0] = ((i % n) + 1);
                    answer[1] = ((i / n) + 1);
                    
                    return answer;
                }
            }
        }
        
        // 이전 단어의 마지막 알파벳과 현재 단어의 첫 알파벳이 다른 경우 (끝말잇기 규칙 위반)
        else {
            
            answer[0] = ((i % n) + 1);
            answer[1] = ((i / n) + 1);
            
            return answer;
        }
    }

    return answer;
}