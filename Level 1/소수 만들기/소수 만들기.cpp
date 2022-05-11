/*
    풀이법
    1. 1-1000 까지의 서로 다른 수 3개를 조합해 나올 수 있는 가장 큰 수는 2997
        2997 크기의 배열을 선언해 에라토스테네스의 체를 이용해 소수를 구해 놓는다.
    2. nums의 0번째 인덱스 부터 0+1, 0+2번째 인덱스의 합을 이용해 1번에서 구해놓은 배열과 대응시켜 소수임을 판별한다.
*/

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    
    int answer = 0;
    
    bool prime_array[2998];
    
    for (int i = 2; i < 2998; i++) {
        
        prime_array[i] = true;
    }
    
    for (int i = 2; (i * i) < 2998; i++) {
        
        if (prime_array[i]) {
            
            for (int j = (i * i); j < 2998; j += i) {
                
                prime_array[j] = false;
            }
        }
    }
    
    for (int i = 0; i < (nums.size() - 2); i++) {
        
        for (int j = (i + 1); j < (nums.size() - 1); j++) {
            
            for (int k = (j + 1); k < nums.size(); k++) {
                
                if (prime_array[nums.at(i) + nums.at(j) + nums.at(k)]) {
                    
                    answer++;
                }
            }
        }
    }

    return answer;
}