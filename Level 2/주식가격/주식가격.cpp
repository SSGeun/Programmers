/*
    풀이법
    1. answer의 요소를 0으로 초기화
    2. answer의 인덱스 기준 prices의 다음 요소부터 순회하며 이전 값보다 작아지면 stop
       (이전 값보다 크면 answer 1씩 증가)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++) {
        
        answer.push_back(0);
        
        for (int j = (i + 1); j < prices.size(); j++) {
            
            answer.at(i)++;
            
            if (prices.at(j) < prices.at(i)) {
                
                break;
            }
        }
    }
    
    return answer;
}