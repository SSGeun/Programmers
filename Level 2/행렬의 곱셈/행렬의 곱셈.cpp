/*
    풀이법
    1. 두 행렬의 곱셈 결과의 한 행을 담을 result_row 배열 선언
    2. 곱셈을 수행하며 한 행이 마무리되면 answer 배열에 할당
        (할당 후 result_row 배열 초기화)
    3. 2번 과정 반복 수행
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    vector<vector<int>> answer;
    
    // answer의 각 행을 담은 배열
    vector<int> result_row;
    
    for (int i = 0; i < arr1.size(); i++) {
        
        for (int j = 0; j < arr2.at(0).size(); j++) {
            
            int result = 0;
            
            for (int k = 0; k < arr1.at(0).size(); k++) {
                
                result += (arr1.at(i).at(k) * arr2.at(k).at(j)); 
            }
            
            result_row.push_back(result);
        }
        
        answer.push_back(result_row);
        result_row.clear();
    }
    
    return answer;
}