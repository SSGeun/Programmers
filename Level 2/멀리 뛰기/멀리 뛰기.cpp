#include <vector>

using namespace std;

long long solution(int n) {
    
    long long answer = 0;
    vector<int> fibonacci;
    
    fibonacci.push_back(1);
    fibonacci.push_back(2);
    
    for (int i = 2; i < n; i++) {
        
        fibonacci.push_back((fibonacci[i - 2] + fibonacci[i - 1]) % 1234567);
    }
    
    answer = fibonacci[n - 1];
    
    return answer;
}