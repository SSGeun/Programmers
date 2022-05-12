#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    
    string answer = "";
    
    int left_hand = 10;
    int right_hand = 12;
    
    for (int i = 0; i < numbers.size(); i++) {
        
        if (numbers.at(i) == 0) {
            
            numbers.at(i) = 11;
        }
        
        // 1, 4, 7은 왼손
        if ((numbers.at(i) % 3) == 1) {
            
            answer += "L";
            left_hand = numbers.at(i);
        }
        
        // 3, 6, 9는 오른손
        else if ((numbers.at(i) % 3) == 0) {
            
            answer += "R";
            right_hand = numbers.at(i);
        }
        
        // 2, 5, 8, 0의 경우
        else {
            
            // 왼손, 오른손의 다음 키패드까지의 거리 계산
            int left_distance = abs(numbers.at(i) - left_hand);
            int right_distance = abs(numbers.at(i) - right_hand);
            
            // 거리가 1보다 큰 경우 실제 거리로 계산
            // Ex> 1에서 5까지의 거리는 4, 이를 2칸으로 환산
            if (left_distance > 1) {
                
                left_distance -= (2 * (left_distance / 3));
            }
            
            if (right_distance > 1) {
                
                right_distance -= (2 * (right_distance / 3));
            }
            
            // 양 손의 거리가 같은 경우
            if (left_distance == right_distance) {
                
                if (hand == "left") {
                    
                    answer += "L";
                    left_hand = numbers.at(i);
                }
                
                else if (hand == "right") {
                    
                    answer += "R";
                    right_hand = numbers.at(i);
                }
            }
            
            // 왼손이 더 가까운 경우
            else if (left_distance > right_distance) {
                
                answer += "R";
                right_hand = numbers.at(i);
            }
            
            // 오른손이 더 가까운 경우
            else {
                
                answer += "L";
                left_hand = numbers.at(i);
            }
        }
    }
    return answer;
}