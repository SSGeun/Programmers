#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    vector<int> answer;
    
    int index = 0;
        
    for (int i = (index + 1); i < arr.size(); i++) {
            
        if (arr.at(index) != arr.at(i)) {
                
            answer.push_back(arr.at(index));
            index = i;
        }
        
        if (i == (arr.size() - 1)) {
            
            answer.push_back(arr.at(index));
            break;
        } 
    }
    
    return answer;
}