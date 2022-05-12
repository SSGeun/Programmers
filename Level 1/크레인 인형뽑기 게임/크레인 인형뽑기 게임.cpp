/*
    풀이법
    1. 크레인을 이용해 뽑은 값을 저장할 result 배열 선언
    2. moves 배열의 각 인덱스 값과 board의 열을 대응해 0이 아닌 값을 뽑아 result 배열로 할당
        (할당된 열의 값은 0으로 초기화)
    3. result 배열의 크기가 2이상이 될 경우 마지막 두 요소를 비교해 값이 같으면 삭제하고 answer 값 2 증가
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    
    vector<int> result;
    
    for (int i = 0; i < moves.size(); i++) {
        
        for (int j = 0; j < board.at(0).size(); j++) {
            
            // moves의 각 인덱스와 대응하는 열의 값이 0이 아닐 경우 해당 값을 result 배열로
            if (board.at(j).at(moves.at(i) - 1) != 0) {
                
                result.push_back(board.at(j).at(moves.at(i) - 1));
                board.at(j).at(moves.at(i) - 1) = 0;
                
                // result 배열의 크기가 2이상일 경우 마지막 두 개의 요소 값이 같을 경우 제거하고 answer 값 2증가
                int result_size = result.size();
                
                if (result_size >= 2) {
                    
                    if (result.at(result_size - 1) == result.at(result_size - 2)) {

                        result.pop_back();
                        result.pop_back();
                        answer += 2;
                    }
                }
                
                break;
            }
        }
    }
    
    return answer;
}