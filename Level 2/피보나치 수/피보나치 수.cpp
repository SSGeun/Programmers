/*
    풀이법
    Hint) 피보나치 수의 경우 n이 커질 수록 값이 기하급수적으로 증가하므로 int형으로 커버 불가능
    Hint) F(n) 요소에 값을 저장하는 것이 아닌 1234567로 나눈 나머지를 저장
		  즉, F(n) = F(n - 1) + F(n - 2) 수식을 활용해
		  F(n) = ((F(n - 1) % 1234567) + (F(n - 2) % 1234567)) % 1234567 의 값을 저장
*/

#include <string>
#include <vector>

using namespace std;

// long long fibonacci(int n);

int solution(int n) {
    
    int answer = 0;
    
    vector<int> fibonacci;
    
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        
        fibonacci.push_back(((fibonacci.at(i - 1) % 1234567) + (fibonacci.at(i - 2) % 1234567)) % 1234567);
    }
    
    answer = fibonacci.at(n);
    
    return answer;
}

/*
long long fibonacci(int n) {
    
    if (n == 0) {
        
        return 0;
    }
    
    else if (n == 1) {
        
        return 1;
    }
    
    else {
        
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
*/