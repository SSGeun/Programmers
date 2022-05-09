/*
    풀이법
    삽입 정렬(Insertion Sort)를 이용해 정렬 후, strings 벡터를 answer 벡터로 복사했습니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    
    vector<string> answer;
    
    int i, j;
    
    for (i = 1; i < strings.size(); i++) {
        
        string key = strings.at(i);
        
        for (j = (i - 1); j >= 0; j--) {
            
            if (strings.at(j).at(n) > key.at(n)) {
                
                strings.at(j + 1) = strings.at(j);
            }
            
            else if (strings.at(j).at(n) == key.at(n)) {
                
                if (strings.at(j) > key) {
                    
                    strings.at(j + 1) = strings.at(j);
                }
                
                else {
                    
                    break;
                }
            }
            
            else {
                
                break;
            }
        }
        
        strings.at(j + 1) = key;
    }
    
    answer.clear();
    answer.assign(strings.begin(), strings.end());
    
    return answer;
}