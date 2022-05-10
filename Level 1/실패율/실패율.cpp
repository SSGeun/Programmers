/*
    풀이법
    1. 2차원 배열을 활용해 1행에는 배열의 인덱스 값을, 2행에는 해당 인덱스를 stage와 대응해 인원 수 저장
        (1행에 배열의 인덱스 값을 복사하는 이유는 정렬 시 이용하기 위함)
    2. stages의 크기, 즉 인원 수를 이용해 각 스테이지의 실패율 계산
    3. 2차원 배열의 2행을 기준으로 실패율에 따른 내림차순 정렬
    4. answer 벡터에 2차원 배열의 1행, 즉 내림차순으로 정렬된 스테이지 할당
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    
    vector<int> answer;
    
    double result[501][2];
    
    // 사용자 수
    int people = stages.size();
    
    // 배열 초기화
    for (int i = 1; i <= N + 1; i++) {
        
        // 인덱스 값을 저장하는 이유? 정렬 시 사용
        result[i][0] = i;
        result[i][1] = 0;
    }
    
    // stages 각 인덱스의 값 count로 할당
    for (int i = 0; i < stages.size(); i++) {
        
        if (stages.at(i) > N) {
            
            continue;
        }
        
        result[stages.at(i)][1]++;
    }
    
    // 각 stage의 실패율 계산해서 result 배열 갱신
    for (int i = 1; i <= N; i++) {
        
        int temp = 0;
        
        if (result[i] != 0) {
            
            temp = result[i][1];
            
            result[i][1] /= people;
            
            people -= temp;
        }
    }
    
    // 실패율 기준으로 내림차순 정렬
    int i, j, index;
    double key;
    
    for (i = 2; i <= N; i++) {
        
        index = result[i][0];
        key = result[i][1];
        
        for (j = (i - 1); j >= 1; j--) {
            
            if (result[j][1] < key) {
                
                result[j + 1][0] = result[j][0];
                result[j + 1][1] = result[j][1];
            }
            
            else {
                
                break;
            }
        }
        
        result[j + 1][0] = index;
        result[j + 1][1] = key;
    }
    
    // 정렬된 스테이지 할당
    for (int i = 1; i <= N; i++) {
        
        answer.push_back(result[i][0]);
    }
    
    return answer;
}