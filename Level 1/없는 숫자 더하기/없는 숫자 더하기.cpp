/*
    풀이법
    1. 1-9까지의 합은 45
    2. numbers의 각 인덱스 값을 45에서 뺀다.
    3. 나머지가 답
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    
    int answer = 45;
    
    for (int i = 0 ; i < numbers.size(); i++) {
        
        answer -= numbers.at(i);
    }
    
    return answer;
}