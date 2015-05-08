//DP 
#include<cstdio>
#include<cstring>
#define SIZE 1000000

long long dp[SIZE], q;

long long calc(long long n) {
	if (n == 0) return 0;
	
	if (n < SIZE && dp[n] != 0) {
		return dp[n];
	}
	
	else {
		long long s = calc(n/2) + calc(n/3) + calc(n/4);
		if (s > n) {
			if (n < SIZE) dp[n] = s;
			return s;
		}
		else {
			if (n < SIZE) dp[n] = n;
			return n;
		}
	}
}					

int main() {
	while (scanf("%lld",&q) != EOF) {
		printf("%lld\n",calc(q));
	}
	return 0;
}		
