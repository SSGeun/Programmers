/*
    풀이법
    1. 폰켓몬의 종류 수 만큼의 크기를 갖는 bool형의 배열 number 선언
    2. nums의 폰켄몬 번호와 number의 인덱스를 대응하여 true 할당
        (이때, nums 배열 안의 폰켓몬 종류 수 계산)
    3-1. N / 2 >= 폰켓몬 종류 수의 경우, answer = 폰켓몬 종류 수
    3-2. N / 2 <= 폰켓몬 종류 수의 경우, answer = N / 2
*/

#include <vector>

using namespace std;

int solution(vector<int> nums) {
    
    int answer = 0;
    
    bool number[200001] = { false, };
    
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        
        if (number[nums.at(i)]) {
            
            continue;
        }
        
        number[nums.at(i)] = true;
        count++;
    }
    
    if (count <= (nums.size() / 2)) {
        
        answer = count;
    }
        
    else {
        
        answer = (nums.size() / 2);   
    }
    
    return answer;
}