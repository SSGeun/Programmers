/*
    -- 전체 문자열 s에서의 각 숫자의 등장 횟수로 판단
    1. 튜플 원소의 최댓값 100,000 크기의 배열 선언
    2. 각 튜플 원소의 인덱스 값을 1씩 증가
    3. 가장 많이 등장한 원소부터 answer에 추가
    4. 등장 횟수가 1인 원소를 마지막으로 종료
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    
    vector<int> answer;
    
    string temp = "";
    
    // 원소의 등장 횟수
    int arr[100001];
    
    for (int i = 0; i < 100001; i++) {
        
        arr[i] = 0;
    }
    
    // 주어진 문자열 s의 각 원소를 파악하여 배열 값 증가
    for (int i = 1; i < (s.length() - 1); i++) {
        
        if (s.at(i) == '{') {
            
            continue;
        }
        
        else if (s.at(i) == '}') {
            
            if (temp != "") {
                
                arr[stoi(temp)] += 1;
                temp = "";
            }
            
            if (s.at(i + 1) == ',') {
                
                i += 1;
            }
        }
        
        else if (s.at(i) == ',') {
            
            arr[stoi(temp)] += 1;
            temp = "";
        }
        
        else {
            
            temp += s.at(i);
        }
    }
    
    // 가장 많이 등장한 원소의 갯수
    int max_count = 0;
    
    for (int i = 0; i < 100001; i++) {
        
        if (arr[i] > max_count) {
            
            max_count = arr[i];
        }
    }
    
    // 가장 많이 등장한 원소부터 answer에 추가
    while (max_count != 0) {
        
        for (int i = 0; i < 100001; i++) {
            
            if (arr[i] == max_count) {
                
                answer.push_back(i);
                break;
            }
        }
        
        max_count -= 1;
    }
    
    return answer;
}