#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

void changedp(int* returnArray, int* coinVals, int A, int numCoins) {
    int *optimalSoln = malloc(A * sizeof(int));
    optimalSoln[0] = 0;
    
    int *S = malloc(A * sizeof(int));
    int coin = 0;
    
    for(int i = 1; i <= A; i++) {
        int min = INT_MAX;
        for(int j = 0; j < numCoins; j++) {
            if(coinVals[j] <= i) {
                if(1 + optimalSoln[i-coinVals[j]] < min) {
                    min = 1 + optimalSoln[i - coinVals[j]];
                    coin = j;
                }
            }
        }
        optimalSoln[i] = min;
        S[i] = coin;
    }
    
    int numCoinsNeeded = optimalSoln[A];
    
    while (A > 0){
        returnArray[S[A]]++;
        A = A - coinVals[S[A]];
    }
    
    /*printf("[");
    for(int i = 0; i < numCoins-1; i++){
        printf("%d, ", returnArray[i]);
    }
    printf("%d]\n\n", returnArray[numCoins-1]);
    printf("%d\n", numCoinsNeeded);
    */
}

int main(){
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    int size = 4;
    int coinVals[] = {1, 5, 10, 25};
    
    for(int i = 2010; i <= 2200; i+=5) {
        int returnArray[] = {0,0,0,0,0,0,0,0};
        gettimeofday(&start, NULL);
        changedp(returnArray, coinVals, i, size);
        gettimeofday(&stop, NULL);
        printf("%d\n", stop.tv_usec - start.tv_usec);
    }
    
    return 0;
}

