#include<cstdio>
#include<cstring>
int t, n, k, i, j, size;
bool fixed[40], flag;
long dp[40][40];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n, &k);
		n <<= 1;
		while (k--) {
			scanf("%d",&i);
			fixed[i-1] = 1;
		}
		memset(dp,0,sizeof(dp));
		size=2;
		for (i=0,j=i+1; j<n; i++,j++) {
			if (!fixed[j]) dp[i][j]=1;
		}
		for (size=4; size<=n; size+=2) {
			for (i=0,j=size+i-1; j<n; i++,j++) {
				if (!fixed[j]) {
					dp[i][j] = dp[i+1][j-1];
					printf("dp[%d][%d] %ld\n",i,j,dp[i][j]);
					flag=true;
					for (k=i+1; k<j; k+=2) {
						if (fixed[k]) flag=false;
						
						dp[i][j] += (dp[i][k]*dp[k+1][j]);
						printf("dp[%d][%d] %ld\n",i,j,dp[i][j]);
					}
					if (flag) {
						dp[i][j] -= ((size/2) - 2);
					}	
					printf("dp[%d][%d] %ld\n",i,j,dp[i][j]);
				}
			}
		}
		
		printf("%ld\n",dp[0][n-1]);
	}
	return 0;
}							
