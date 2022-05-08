#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    vector<int> answer;
    
    // vector의 크기가 1, 즉 배열에 수가 1개인 경우
    if (arr.size() == 1) {
        
        answer.push_back(-1);
    }
    
    else {
        
        int index = 0;
        
        // 가장 작은 수 index 찾기
        for (int i = 1; i < arr.size(); i++) {
            
            if (arr.at(index) > arr.at(i)) {
                
                index = i;
            }
        }
        
        // 가장 작은 수 삭제
        arr.erase(arr.begin() + index);
        
        // answer vector로 복사
        for (int i = 0; i < arr.size(); i++) {
            
            answer.push_back(arr.at(i));
        }
    }
    
    return answer;
}