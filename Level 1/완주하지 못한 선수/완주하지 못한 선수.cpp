#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    
    /*
        1. 동일한 이름 지우고, 남은 participant가 답
    */
//     for (int i = 0; i < participant.size(); i++) {
        
//         for (int j = 0; j < completion.size(); j++) {
            
//             if (participant.at(i) == completion.at(j)) {
                
//                 participant.erase(participant.begin() + i);
//                 completion.erase(completion.begin() + j);
//                 j--;
//                 i--;
//                 break;
//             }
//         }
//     }
    
    
    /*
        2. completion에 이름이 없을 시 그 이름이 답
    */
//     for (int i = 0; i < participant.size(); i++) {
        
//         int count = 0;
        
//         for (int j = 0; j < completion.size(); j++) {
            
//             if (participant.at(i) == completion.at(j)) {
                
//                 participant.erase(participant.begin() + i);
//                 completion.erase(completion.begin() + j);
//                 j--;
//                 i--;
//                 count++;
//                 break;
//             }
//         }
        
//         if (count == 0) {
            
//             answer += participant.at(i);
//             break;
//         }
//     }
    
    
    /*
        3. 두 배열 정렬 후, 각 인덱스가 다른 경우 답
    */
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0 ; i < participant.size(); i++) {
        
        if (i == (participant.size() - 1)) {
            
            answer = participant.at(i);
            break;
        }
        
        if (participant.at(i) != completion.at(i)) {
            
            answer = participant.at(i);
            break;
        }
    }    
    
    return answer;
}