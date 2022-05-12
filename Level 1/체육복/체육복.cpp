/*
    풀이법
    1. 최초 전체 학생 수(n) 모두가 체육복을 소지하고 있다고 가정하고 1로 초기화
        (student의 크기를 n+2로 잡은 이유는 빌려주는 반복문에서 0, n+1 인덱스를 사용하기 위함)
    2. 체육복을 도난 당한 학생들은 0으로 감소
    3. 여벌의 체육복을 가진 학생들은 2로 증가
    4. 여벌의 체육복을 가진 학생 기준 앞, 뒤에 체육복이 없는 학생을 찾아 1씩 빌려줌
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = 0;
    
    int student[n + 2];
    
    // 최초 모든 학생이 체육복을 가지고 있다고 가정
    for (int i = 0; i < (n + 2); i++) {
        
        student[i] = 1;
    }
    
    // 체육복을 도난당한 학생들 확인
    for (int i = 0; i < lost.size(); i++) {
        
        student[lost.at(i)]--;
    }
    
    // 여벌의 체육복을 가진 학생들 확인
    for (int i = 0; i < reserve.size(); i++) {
        
        student[reserve.at(i)]++;
    }
    
    // 여벌의 체육복을 가진 학생들은 바로 앞, 뒤 도난당한 학생들에게 빌려줌
    for (int i = 1; i < (n + 1); i++) {
        
        if (student[i] == 2) {
            
            if (student[i - 1] == 0) {
                
                student[i]--;
                student[i - 1]++;
            }
            
            else if (student[i + 1] == 0) {
                
                student[i]--;
                student[i + 1]++;
                i++;
            }
        }
    }
    
    // 총 몇 명의 학생이 체육복을 갖는지 확인
    for (int i = 1; i < (n + 1); i++) {
        
        if (student[i] >= 1) {
            
            answer++;
        }
    } 
    
    return answer;
}