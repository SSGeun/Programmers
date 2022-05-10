/*
    풀이법
    1. arr1, arr2 두 배열의 각 값 OR 연산 수행
    2. OR 연산의 결과 값을 2진수로 변환 (이때 역순으로 저장됨을 인지)
    3. 2진수로 변환된 값을 '#', ' '으로 대체
        이때, 결과값이 주어진 n의 값보다 작을 경우 남은 자리는 ' '으로 대체
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    
    // arr1, arr2의 OR 연산 결과값 저장
    vector<int> or_arr;
    
    // arr1, arr2 각 인덱스 OR 연산 수행
    for (int i = 0; i < n; i++) {
        
        or_arr.push_back(arr1.at(i) | arr2.at(i));
    }
    
    // OR 연산의 결과를 2진수로 변환
    for (int i = 0; i < n; i++) {
        
        string result = "";
        string result_reverse = "";
        
        for (int j = 0; j < n; j++) {
            
            // 2진수의 값이 n 값보다 작을 경우 공백으로 대체
            if (or_arr.at(i) == 0) {
                
                result += " ";
                continue;
            }
            
            result += ( or_arr.at(i) % 2 == 0 ? " " : "#" );
            or_arr.at(i) /= 2;
        }
        
        // result의 저장된 2진수 값을 역순으로 출력
        for (int j = (result.length() - 1); j >= 0; j--) {
            
            result_reverse += result.at(j);
        }
        
        answer.push_back(result_reverse);
    }
    
    return answer;
}