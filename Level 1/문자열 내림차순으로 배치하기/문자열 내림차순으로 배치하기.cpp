/*
    풀이법
    대문자 A부터 Z를 아스키 코드 값으로 치환하면 65에서 90
    소문자 a부터 z를 아스키 코드 값으로 치환하면 97에서 122
    
    1. int형의 크기 123 배열을 통해 각 알파벳에 해당하는 인덱스 값에 알파벳 출현 횟수 기록
    2. 소문자를 역순으로 나온 횟수만큼 출력
    3. 대문자를 역순으로 나온 횟수만큼 출력
*/



#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    string answer = "";
    
    // 배열 선언 및 초기화
    int alphabet_arr[123] = { 0, };
    
    // 문자열 s 각 자리의 알파벳 배열에 추가
    for (int i = 0; i < s.length(); i++) {
        
        alphabet_arr[s.at(i)]++;
    }
    
    // 소문자를 역순으로 나온 횟수만큼 출력
    for (int i = 122; i >= 97; i--) {
        
        if (alphabet_arr[i] == 0) {
            
            continue;
        }
        
        for (int j = 0; j < alphabet_arr[i]; j++) {
            
            answer += i;
        }
    }
    
    // 대문자를 역순으로 나온 횟수만큼 출력
    for (int i = 90; i >= 65; i--) {
        
        if (alphabet_arr[i] == 0) {
            
            continue;
        }
        
        for (int j = 0; j < alphabet_arr[i]; j++) {
            
            answer += i;
        }
    }
    
    return answer;
}