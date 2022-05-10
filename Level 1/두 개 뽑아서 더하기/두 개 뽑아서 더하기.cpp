/*
    풀이법
    1. 크기 201의 bool 형식 배열 result 선언
        (numbers의 최대 값은 100, 즉 최대 두 수의 합은 200)
    2. 두 수의 합과 대응되는 result 배열의 인덱스를 true로 변환
    3. result 배열의 true인 인덱스 출력
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer;
    
    bool result[201] = { false, };
    
    for (int i = 0; i < (numbers.size() - 1); i++) {
        
        for (int j = (i + 1); j < numbers.size(); j++) {
            
            result[numbers.at(i) + numbers.at(j)] = true;
        }
    }
    
    for (int i = 0; i < 201; i++) {
        
        if (result[i]) {
            
            answer.push_back(i);
        }
    }
    
    return answer;
}