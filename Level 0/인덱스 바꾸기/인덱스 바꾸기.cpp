#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    
    string answer = my_string;
    
    char temp = answer.at(num1);
    answer.at(num1) = answer.at(num2);
    answer.at(num2) = temp;
    
    return answer;
}