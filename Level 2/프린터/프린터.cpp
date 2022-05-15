/*
    풀이법
    1. 주어진 배열 priorities에 1-9 각 우선순위 작업이 몇 개씩 존재하는지 파악
    2. priorities의 인덱스 값을 큐에 차례대로 삽입
    3. 우선순위가 높은 작업과 큐의 맨 앞 인덱스를 통해 priorities 배열을 검색해 해당 작업의 우선순위가 다르면,
        큐의 맨 앞 인덱스를 큐의 맨 뒤로 이동
    4. 3번의 과정을 반복하며 우선순위가 높은 작업 순으로 큐에서 pop
    5. 이때, 큐의 저장된 인덱스 값이 location과 같으면 return
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    
    int priorities_num[10] = { 0, };
    
    queue<int> result;
    
    // priorities 배열에 각 우선순위 작업이 몇 개씩 존재하는지 파악
    // priorities 배열의 인덱스를 큐에 삽입
    for (int i = 0; i < priorities.size(); i++) {
        
        priorities_num[priorities.at(i)]++;
        result.push(i);
    }
    
    // 우선순위가 큰 작업부터 찾아나감
    for (int i = 9; i >= 0; i--) {
        
        // 개수가 0이 아니면 반복
        while (priorities_num[i] != 0) {
            
            // 우선순위가 가장 높은 작업이 큐에 맨 앞의 요소와 다르면 해당 요소를 큐의 맨 뒤로 이동
            if (priorities.at(result.front()) != i) {
                
                result.push(result.front());
                result.pop();
            }
            
            // 우선순위가 가장 높은 작업 먼저 수행
            else {
            
                answer++;
                priorities_num[i]--;
                
                // 해당 작업이 location과 같으면 return
                if (result.front() == location) {
                    
                    return answer;
                }
                    
                result.pop();
            }
        }
    }
    
    return answer;
}