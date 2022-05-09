/*
    풀이법
    1. 해당 년도의 1월 1일이 무슨 요일인지 확인
    2. 1월 1일에서 원하는 날짜 사이의 간격 구하기
    3. 날짜의 간격을 7로 나눈 나머지를 요일 인덱스로 활용
*/

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    string answer = "";
    
    int months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    
    int sum = 0;
    
    for (int i = 0; i < (a - 1); i++) {
        
        sum += months[i];
    }
    
    answer = days[(sum + b) % 7];
    
    return answer;
}