/*
    풀이법
    1. 주어진 배열 d의 원소들을 오름차순으로 정렬
    2. 배열의 첫 번째 원소부터 주어진 예산 budget에서 뺌, answer 1씩 증가
    3. budget이 0보다 작아질 경우 멈춤
    
    ** 주어진 배열 d의 각 원소들 중 가장 작은 값부터 계산하여 budget에 맞추면 최대한 많은 부서에 금액 할당 가능 ** 
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    
    int answer = 0;
    
    // Insertion Sort
    int i, j, key;
    
    for (i = 1; i < d.size(); i++) {
        
        key = d.at(i);
        
        for (j = (i - 1); j >= 0; j--) {
            
            if (d.at(j) > key) {
                
                d.at(j + 1) = d.at(j);
            }
            
            else {
                
                break;
            }
        }
        
        d.at(j + 1) = key;
    }
    
    for (int i = 0; i < d.size(); i++) {
        
        if ((budget - d.at(i)) >= 0) {
            
            budget -= d.at(i);
            answer++;
        }
    }
    
    return answer;
}