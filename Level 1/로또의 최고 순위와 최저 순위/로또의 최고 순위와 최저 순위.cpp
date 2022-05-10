/*
    풀이법
    1. 로또 번호가 1-45 이므로 해당 크기의 배열 arr 선언
    2. lottos 배열의 번호와 arr 배열의 인덱스를 대응시켜 true
        (이때, lottos의 0이 몇 번 등장하는지 확인)
    3. lottos 배열의 번호와 win_nums 배열의 번호가 몇 개 일치하는지 확인
    4. 일치한 번호 수가 곧 최저 순위가 되고, 일치한 번호 + 0 등장 횟수가 최고 순위가 됨
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    vector<int> answer;
    bool arr[46] = { false, };
    int result[7] = { 6, 6, 5, 4, 3, 2, 1 };
    
    int zero_count = 0;
    int count = 0;
    
    for (int i = 0; i < lottos.size(); i++) {
        
        if (lottos.at(i) == 0) {
            
            zero_count++;
            continue;
        }
        
        arr[lottos.at(i)] = true;
    }
    
    for (int i = 0; i < win_nums.size(); i++) {
        
        if (arr[win_nums.at(i)]) {
            
            count++;
        }
    }
    
    switch (count) {
            
        case 6:
            answer.push_back(6);
            answer.push_back(6);
            break;   
            
        case 5:
            answer.push_back(5 + zero_count);
            answer.push_back(5);
            break;   
            
        case 4:
            answer.push_back(4 + zero_count);
            answer.push_back(4);
            break;   
            
        case 3:
            answer.push_back(3 + zero_count);
            answer.push_back(3);
            break;   
            
        case 2:
            answer.push_back(2 + zero_count);
            answer.push_back(2);
            break;   
            
        case 1:
            answer.push_back(1 + zero_count);
            answer.push_back(1);
            break;   
            
        case 0:
            answer.push_back(0 + zero_count);
            answer.push_back(0);
            break;
    }
    
    for (int i = 0; i < answer.size(); i++) {
        
        answer.at(i) = result[answer.at(i)];
    }
    
    return answer;
}