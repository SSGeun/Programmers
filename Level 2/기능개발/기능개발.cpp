/*
    풀이법
    1. 주어진 배열 progresses와 speeds를 가지고 각 작업이 끝나는데까지 걸리는 일자를 구한다. (result 배열에 저장)
    2. result 배열을 통해 선행 작업을 비교해 정답을 구한다.
    
    Hint) result 배열의 각 인덱스를 비교해 앞의 요소보다 더 큰 뒤의 요소의 개수를 찾는다.
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    
    // 일자 저장할 배열
    vector<int> result;
    
    // 각 작업의 진도가 100% 되는데까지 걸리는 일자
    for (int i = 0; i < progresses.size(); i++) {
        
        int j = 1;
        
        while (true) {
            
            if (progresses.at(i) + (speeds.at(i) * j) >= 100) {
                
                result.push_back(j);
                break;
            }
            
            else {
                
                j++;
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        
        int day = 1;
        
        for (int j = (i + 1); j < result.size(); j++) {
            
            if (result.at(i) >= result.at(j)) {
                
                day++;
            }
            
            else {
                
                break;
            }
        }
        
        answer.push_back(day);
        i += (day - 1);
    }
    
    return answer;    
}