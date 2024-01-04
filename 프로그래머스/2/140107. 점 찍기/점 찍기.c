#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int k, int d) {
    long long answer = 0;
    long long D = d;
    long long K = k;
    for(int i=0;i<=D;i+=K){
        long long res = floor(sqrt((long long)D*D-(long long)i*i));
        answer += res/K+1;
    }
    
    return answer;
}