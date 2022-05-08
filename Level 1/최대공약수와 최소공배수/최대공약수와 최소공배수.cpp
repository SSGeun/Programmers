#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b);

vector<int> solution(int n, int m) {
    
    vector<int> answer;
    
    int gcd_result = gcd(n, m);
    
    answer.push_back(gcd_result);
    answer.push_back((n * m) / gcd_result);
    
    return answer;
}

// 유클리드 호제법
int gcd(int a, int b) {
    
    int r;
    
    while (b != 0) {
        
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}