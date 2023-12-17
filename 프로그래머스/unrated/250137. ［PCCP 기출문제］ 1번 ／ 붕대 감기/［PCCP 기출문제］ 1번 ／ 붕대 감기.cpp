#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int last = attacks[attacks.size()-1][0];
        int idx = 0;
        int count = 0;
        int initHealth = health;
        int flag=0;
        for(int i=1;i<=last;i++){
            if(attacks[idx][0]==i){
                health -= attacks[idx][1];
                if(health<=0){
                    flag=1;
                    break;
                }
                idx++;
                count=0;
            }else{
                health += bandage[1];
                count++;
                if(count == bandage[0]){
                    health+=bandage[2];
                    count=0;
                }
                if(health > initHealth){
                    health = initHealth;
                }
            }
        }
        if(flag == 1){
            answer = -1;
        }else{
            answer = health;
        } 
    
    return answer;
}