//DP
#include <cstdio>
#define MAXN 100005

int n, k, i, j, sum[6];
bool dp[MAXN];

int main() {
	scanf("%d %d %d", &n, &k, &sum[0]);
	for (i=1; i<k; i++) {
		scanf("%d",&sum[i]);
		sum [i] += sum[i-1];
	}
	
	for (i=0; i<=n; i++) dp[i] = false;
	
	dp[0] = true;
	
	for (i=0; (i+sum[0])<=n; i++) {
		if (dp[i]) dp[i+sum[0]] = true;
	}	
			
	for (j=1; j<k; j++) {
		for (i=0; (i+sum[j])<=n; i++) {
			if (dp[i]) dp[i+sum[j]] = true;
		}
	}	
	
	if (dp[n]) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
