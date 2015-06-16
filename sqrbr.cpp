#include<cstdio>
#include<cstring>

int t, n, k, i, j, indx, status;
bool fixed[40];
long dp[40][40];	
	
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n, &k);
		n <<= 1;
		memset(fixed,0,sizeof(fixed));
		memset(dp,0,sizeof(dp));
		
		while (k--) {
			scanf("%d",&i);
			fixed[i-1] = 1;
		}
		
		dp[n][0] = 1;
		for (indx = n-1; indx > 0; indx--) {
			for (status=0; status <= n/2; status++) {
				dp[indx][status] = dp[indx+1][status+1];
				if (!fixed[indx] && status>0) {
					dp[indx][status] += dp[indx+1][status-1];
				}
			}
		}			
		
		printf("%ld\n",dp[1][1]);
	}
	return 0;
}							
