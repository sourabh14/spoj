//DP with space optimization
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, i, j, x, y, k, dp[2][5003];
char str[5003];

int main() {
	scanf("%d %s", &n, str);
	memset(dp, 0, sizeof dp);
	
	for (i=n-2; i>=0; i--) {
		for (j=i+1; j<n; j++) {
			x = i%2; y = (i+1)%2;
			if (str[i] == str[j]) dp[x][j] = dp[y][j-1];
			else dp[x][j] = min(dp[y][j], dp[x][j-1]) + 1;
		}
	}
	
	printf("%d\n",dp[0][n-1]);
	return 0;
}		
