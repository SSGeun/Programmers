/*
    풀이법
    Hint) 두 배열에 각 요소 곱의 합이 최소가 되려면 A배열의 가장 큰 수와 B배열의 가장 작은 수의 곱을 더하여 한다.
    
    1. 주어진 두 배열 A, B를 정렬한다.
    2. A의 가장 작은 수와 B의 가장 큰 수를 곱한 후 answer 변수에 더해준다.
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    int answer = 0;

    // 두 배열 A, B 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for (int i = 0; i < A.size(); i++) {
        
        int multiple = (A.at(i) * B.at(B.size() - 1 - i));
        
        answer += multiple;
    }
    
    return answer;
}