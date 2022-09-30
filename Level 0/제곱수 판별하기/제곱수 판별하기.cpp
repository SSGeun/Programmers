#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    
    int n_sqrt = sqrt(n);
    int answer = ((n_sqrt * n_sqrt) == n) ? 1 : 2;
    
    return answer;
}