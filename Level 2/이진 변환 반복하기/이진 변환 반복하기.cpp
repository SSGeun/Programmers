#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    
    vector<int> answer;
    
    int count = 0;
    int remove_zero = 0;
    
    while (s != "1") {
        
        int length = 0;
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {

            if (s.at(i) == '1') {

                length++;
            }
        }

        remove_zero += (s.length() - length);
        count++;
        s = "";

        while (length != 0) {

            s += to_string(length % 2);
            length /= 2;
        }
    }
    
    answer.push_back(count);
    answer.push_back(remove_zero);
    
    return answer;
}