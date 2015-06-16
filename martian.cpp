//DP
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, i, j, y, b;
long Y[505][505], B[505][505], dp[505][505];
//Y[i][j] is horiz sum of y of ith row from 0 to j 
//B[i][j] is vertical sum of b of ith column from 0 to j

int main() {
	for (i=0; i<=n; i++) {
		Y[i][0] = 0;
		dp[i][0] = 0;
	}
	for (i=0; i<=m; i++) {
		B[0][i] = 0;
		dp[0][i] = 0;
	}	
	
	scanf("%d %d",&n, &m);
	while (n>0) {
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				scanf("%ld",&Y[i][j]);
				Y[i][j] += Y[i][j-1];
			}
		} 
		
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				scanf("%ld",&B[i][j]);
				B[i][j] += B[i-1][j];
			}
		}		
		
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) {
				dp[i][j] = max(dp[i][j-1]+B[i][j], dp[i-1][j]+Y[i][j]);
			}
		}		
		
		printf("%ld\n",dp[n][m]);
		scanf("%d %d",&n, &m);
	}
	return 0;
}			
