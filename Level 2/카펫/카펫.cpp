#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    
    int sum = (brown + yellow);
    int sum_sqrt = sqrt(sum);
    
    while (1) {
        
        if ((sum % sum_sqrt) == 0) {
            
            if (((sum_sqrt * 2) + (sum / sum_sqrt * 2) - 4) == brown) {
            
                if (sum_sqrt >= (sum / sum_sqrt)) {

                    answer.push_back(sum_sqrt);
                    answer.push_back(sum / sum_sqrt);
                    break;
                }

                else {

                    answer.push_back(sum / sum_sqrt);
                    answer.push_back(sum_sqrt);
                    break; 
                }
            }
            
            else {
                
                sum_sqrt++;
            }
        }
        
        else {
            
            sum_sqrt++;
        }
    }
    
    return answer;
}