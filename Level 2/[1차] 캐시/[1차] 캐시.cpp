#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    int answer = 0;
    vector<string> lru;
    
    // cacheSize가 0인 경우 무조건 miss
    if (cacheSize == 0) {
        
        answer = (5 * cities.size());
    }
    
    // cacheSize가 0보다 큰 경우
    else {
        
        for (int i = 0; i < cities.size(); i++) {

            // lru vector 내에 이미 존재하는지 여부
            bool duplication = false;

            // 대소문자 구분 안하므로 임의로 대문자로 변경
            transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

            // lru가 비어있는 경우 무조건 push
            if (lru.size() == 0) {

                lru.push_back(cities[i]);
                answer += 5;
                continue;
            }

            // lru vector 내에 이미 존재하는 도시인지 확인
            for (int j = 0; j < lru.size(); j++) {

                // 존재하는 경우
                if (lru[j] == cities[i]) {

                    duplication = true;
                    lru.erase(lru.begin() + j);
                    lru.push_back(cities[i]);
                    answer += 1;
                    break;
                }
            }

            // 존재하지 않는 경우
            if (!duplication) {

                // cache가 꽉 찬 경우
                if (lru.size() == cacheSize) {

                    lru.erase(lru.begin());
                    lru.push_back(cities[i]);
                    answer += 5;
                    continue;
                }

                // cache에 여분 공간이 있는 경우
                else {

                    lru.push_back(cities[i]);
                    answer += 5;
                    continue;
                }
            }
        }
    }
    
    return answer;
}