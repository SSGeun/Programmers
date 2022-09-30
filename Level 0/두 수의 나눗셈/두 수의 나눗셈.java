class Solution {
    
    public int solution(int num1, int num2) {
        
        int answer = 0;
        
        double num = ((double)num1 / (double)num2);
        double result = (num * 1000);
        
        answer = (int)result;
        
        return answer;
    }
}