using namespace std;

int solution(int n, int a, int b) {
    
    int answer = 0;
    
    // a와 b의 값이 같아질 때까지 반복
    while (a != b) {
        
        // a와 b의 값을 짝수로
        a = ((a % 2) == 1) ? (a + 1) : a;
        b = ((b % 2) == 1) ? (b + 1) : b;
        
        a /= 2;
        b /= 2;
        answer++;
    }

    return answer;
}