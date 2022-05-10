/*
    풀이법
    1. 주어진 자연수 n의 3진수를 구하여 result에 저장
    2. result의 역순으로 3진수를 10진수로 변환
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    
    string result = "";
    int num = 1;
    
    while (n != 0) {
        
        result += ( n % 3 == 0 ? "0" : to_string(n % 3) );
        n /= 3;
    }
    
    for (int i = (result.length() - 1); i >= 0; i--) {
        
        answer += (result.at(i) - '0') * num;
        num *= 3;
    }
    
    return answer;
}