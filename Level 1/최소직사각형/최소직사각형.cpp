#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int answer = 0;
    
    // 가로 > 세로, 재정렬
    for (int i = 0; i < sizes.size(); i++) {

        if (sizes.at(i).at(0) < sizes.at(i).at(1)) {
                
            int temp = sizes.at(i).at(0);
            sizes.at(i).at(0) = sizes.at(i).at(1);
            sizes.at(i).at(1) = temp;
        }
    }
    
    // 재정렬 후, [0][0]과 [0][1]의 가로, 세로 값이 최댓값으로 설정
    int width = sizes.at(0).at(0);
    int height = sizes.at(0).at(1);
    
    // 가로, 세로 가장 큰 수 찾기
    for (int i = 1; i < sizes.size(); i++) {
        
        if (width < sizes.at(i).at(0)) {
            
            width = sizes.at(i).at(0);
        }
        
        if (height < sizes.at(i).at(1)) {
            
            height = sizes.at(i).at(1);
        }
    }
    
    answer = width * height;
    
    return answer;
}