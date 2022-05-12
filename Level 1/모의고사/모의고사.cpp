/*
    풀이법
    1. 1번, 2번, 3번 수포자가 찍는 방식을 배열로 저장
    2. 주어진 answers 배열을 순회하며 각자 몇 개씩 맞췄는지 확인
    3. 그 중 가장 많이 맞춘 사람의 개수를 찾아 그 개수와 같은 사람이 최고 득점자
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> answer;
    
    // 1번, 2번, 3번 수포자가 찍는 방식
    int first[5] = { 1, 2, 3, 4, 5 };
    int second[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };    
    int third[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int count[3] = { 0, 0, 0 };
    
    // 각자 몇 개씩 맞췄는지 확인
    for (int i = 0; i < answers.size(); i++) {
        
        if (answers.at(i) == first[i % 5]) {
            
            count[0]++;
        }
        
        if (answers.at(i) == second[i % 8]) {
            
            count[1]++;
        }
        
        if (answers.at(i) == third[i % 10]) {
            
            count[2]++;
        }
    }
    
    // 가장 많이 맞춘 개수 확인
    int max_count = count[0];
    for (int i = 1; i < 3; i++) {
        
        if (count[i] > max_count) {
            
            max_count = count[i];
        }
    }
    
    // 가장 많이 맞춘 개수과 같은 사람들이 답
    for (int i = 0; i < 3; i++) {
        
        if (count[i] == max_count) {
            
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}