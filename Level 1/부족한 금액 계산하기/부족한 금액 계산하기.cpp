using namespace std;

long long solution(int price, int money, int count) {
    
    long long answer = -1;
    
    long long sum = 0;
    
    int price_temp = price;
    
    for (int i = 0; i < count; i++) {
        
        sum += price;
        
        price += price_temp;
    }
    
    if (money >= sum) {
        
        answer = 0;
    }
    
    else {
        
        answer = sum - money;
    }

    return answer;
}