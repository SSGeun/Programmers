/*
    풀이법
    1. array 배열 복사
    2. commands 각 행의 정보를 가지고 array 배열 정렬
        (1회전이 끝난 후 array배열이 정렬로 인해 처음과 달라지므로 1번에서 복사한 배열을 이용해 원상태로 복구)
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    
    vector<int> arr_temp;
    
    arr_temp.clear();
    arr_temp.assign(array.begin(), array.end());
    
    int j, k, key;
    
    for (int i = 0; i < commands.size(); i++) {
        
        array.clear();
        array.assign(arr_temp.begin(), arr_temp.end());
        
        for (j = commands.at(i).at(0); j < commands.at(i).at(1); j++) {
            
            key = array.at(j);
            
            for (k = (j - 1); k >= (commands.at(i).at(0) - 1); k--) {
                
                if (array.at(k) > key) {
                    
                    array.at(k + 1) = array.at(k);
                }
                
                else {
                    
                    break;
                }
            }
            
            array.at(k + 1) = key;
        }
        
        answer.push_back(array.at(commands.at(i).at(0) + commands.at(i).at(2) - 2));
    }
    
    return answer;
}