/*
    풀이법
    1. 주어진 arr 배열의 0번부터 배열의 크기까지 반복하며 인접한 두 수의 최소공배수를 구한다.
    2. 0번과 1번 인덱스의 최소공배수를 구해 1번 인덱스에 할당한다.
    3. 2번 과정을 반복하면 arr 배열의 마지막 요소에는 배열 전체의 최소공배수가 저장되어 있음
*/

#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b);

int solution(vector<int> arr) {
    
    int answer = 1;
    
    // 인접한 두 수의 최소공배수를 구해 나간다.
    for (int i = 1; i < arr.size(); i++) {
        
        arr.at(i) = (arr.at(i - 1) * arr.at(i)) / gcd(arr.at(i - 1), arr.at(i));
    }
    
    // 배열의 마지막 요소가 답
    answer = arr.at(arr.size() - 1);
    
    return answer;
}

// 두 수의 최대공약수
int gcd(int a, int b) {
    
    int r;
    
    while (b != 0) {
        
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}