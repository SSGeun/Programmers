#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    
    int answer = 0;
    
    for (int i = 0; i < absolutes.size(); i++) {
    
        // signs가 true, 즉 양수인 경우
        if (signs.at(i)) {
            
            answer += absolutes.at(i);
        }
        
        // signs가 false, 즉 음수인 경우
        else {
            
            answer -= absolutes.at(i);            
        }
    }
    
    return answer;
}