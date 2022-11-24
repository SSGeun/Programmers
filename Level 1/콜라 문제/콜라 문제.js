function solution(a, b, n) {
    
    let answer = 0;
    let temp = 0;
    
    while (true) {
        
        temp += (parseInt(n / a) * b);
        answer += temp;
        n = (n % a) + temp;
        
        temp = 0;
        
        if (n < a) {
            
            break;
        }
    }
    
    return answer;
}