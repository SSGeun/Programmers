/*
    풀이법
    Hint) 자연수 n의 절반 값을 넘어가면 어떤 방법으로도 연속된 수의 합으로 n을 만들 수 없다.
    1. 1부터 n/2까지 연속된 수를 더하며 n이 되면 answer값을 1 증가 시켜준다.
    2. 반복문 수행 과정에서 n이 되거나 n을 넘어서면 멈춘다.
    3. 위의 과정은 n/2 까지만 수행되기 때문에 반복문을 모두 수행한 후,
        자기 자신의 값으로 완성될 수 있는 경우를 추가해 준다. (answer값 1 증가)
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    
    int size = ((n % 2) == 0 ? (n / 2) : ((n / 2) + 1));
    
    for (int i = 1; i < size; i++) {
        
        int sum = i;
        
        for (int j = (i + 1); j <= size; j++) {

            sum += j;

            if (sum == n) {

                answer++;
                break;
            }

            if (sum > n) {

                break;
            }
        }
    }
    
    answer++;
    
    return answer;
}