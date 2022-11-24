function solution(number, limit, power) {
    
    let answer = 0;
    
    for (let i = 1; i <= number; i++) {
        
        let count = 0;
        
        for (let j = 1; j <= Math.sqrt(i); j++) {
            
            if (i % j === 0) {
                
                if (parseInt(i / j) === j) {

                    count++;
                }

                else {

                    count += 2;
                }

                if (count > limit) {

                    count = power;
                    break;
                }
            }
        }
        
        answer += count;
    }
    
    return answer;
}