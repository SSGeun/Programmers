#include <string>

using namespace std;

int solution(string dartResult) {
    
    int answer = 0;
    
    int score[3] = { 0, };
    int index = 0;
    
    for (int i = 0; i < dartResult.length(); i++) {
        
        // 점수
        if (dartResult.at(i) >= '0' && dartResult.at(i) <= '9') {
            
            // 10점인 경우
            if (dartResult.at(i + 1) == '0') {
                
                score[index] = 10;
                i++;
            }
            
            // 0-9점인 경우
            else {
                
                score[index] = dartResult.at(i) - '0';
            }
            
            index++;
            continue;
        }
        
        // 보너스 (S, D, T), cmath 라이브러리의 pow 사용해도 가능
        if (dartResult.at(i) == 'S' || dartResult.at(i) == 'D' || dartResult.at(i) == 'T') {
            
            if (dartResult.at(i) == 'S') {

            }

            else if (dartResult.at(i) == 'D') {
                
                int double_score = score[index - 1] * score[index - 1];
                score[index - 1] = double_score;
            }

            else if (dartResult.at(i) == 'T') {

                int triple_score = score[index - 1] * score[index - 1] * score[index - 1];
                score[index - 1] = triple_score;
            }
            
            continue;
        }
        
        // 옵션 (*, #)
        if (dartResult.at(i) == '*' || dartResult.at(i) == '#') {
            
            if (dartResult.at(i) == '*') {

                if ((index - 1) == 0) {

                    score[index - 1] *= 2;
                }

                else {

                    score[index - 2] *= 2;
                    score[index - 1] *= 2;
                }
            }

            else if (dartResult.at(i) == '#') {

                score[index - 1] *= -1;
            }
            
            continue;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        
        answer += score[i];
    }
    
    return answer;
}