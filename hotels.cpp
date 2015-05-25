#include<cstdio>
#define SIZE 300005

long n, arr[SIZE], i;
long long m, dp[SIZE];

int main() {
	scanf("%ld %lld",&n, &m);
	for (i=0; i<n; i++) scanf("%ld",&arr[i]);
	
	dp[0] = 0;
	if (arr[0] < m) dp[0] = arr[0];
	
	for (i=1; i<n; i++) {
		if (dp[i-1]+arr[i] < m) {
			dp[i] = dp[i-1]+arr[i];
		}
		else {
				
