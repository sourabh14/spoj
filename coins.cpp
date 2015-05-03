//DP
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define SIZE 500000009

using namespace std;

long q, dp[SIZE], i; 

int main() {
	dp[0] = 0; dp[1] = 1; 
	for (i=2 ; i<SIZE; i++) {
		dp[i] = max(i , (dp[i/2] + dp[i/3] + dp[i/4]));
	}	
	
	while (scanf("%ld",&q) != EOF) {
		if (q < SIZE) {
			printf("%ld\n",dp[q]);
		}
		else {
			q = max(q , (dp[q/2] + dp[q/3] + dp[q/4]));
			printf("%ld\n",q);
		}		
	}
	return 0;
}	