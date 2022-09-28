#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    int sum = limit;
    
    // people 배열 오름차순으로 정렬
    sort(people.begin(), people.end());
    
    // 가장 가벼운 사람과 가장 무거운 사람을 태울 수 있는가?
    for (int i = 0; i < people.size(); i++) {
        
        // 무게 제한에서 가장 가벼운 몸무게 빼기
        sum -= people[i];
        
        // 남은 무게 제한에 가장 무거운 사람이 탈 수 있는가?
        for (int j = (people.size() - 1); j > i; j--) {
            
            //가장 가벼운 사람과 함께 탈 수 있는 사람 중, 가장 무거운 사람
            if (people[j] <= sum) {
                
                people.erase(people.begin() + j);
                break;
            }
            
            // 남은 무게 제한에 못타는 사람들
            // 즉, 결국 혼자 타야하는 사람들
            else {
        
                people.erase(people.begin() + j);
                answer++;
            }
        }
        
        answer++;
        sum = limit;
    }
    
    return answer;
}