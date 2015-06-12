//DP
#include<cstdio>
#include<algorithm>
using namespace std;

long n, i, j, s, arr[1003], dp[1003][1003], x, y, g;

int main() {
	g=0;
	scanf("%ld",&n);
	while (n) {
		g++;
		for (i=0; i<n; i++) {
			scanf("%ld",&arr[i]);
			dp[i][i]=arr[i];
		}
		
		for (i=0; i<n-1; i++) {
			dp[i][i+1] = max(arr[i],arr[i+1]);
		}
		
		for (s=2; s<n; s++) {
			for (i=0,j=i+s; j<n; i++,j++) {
				//if player 1 chooses arr[i]
				//then player 2 chooses max(arr[i+1],arr[j])
				if (arr[j]>arr[i+1]) {
					x = arr[i]+dp[i+1][j-1];
				}
				else {
					x =	arr[i]+dp[i+2][j];
				}
				//if player 1 chooses arr[j]
				//then player 2 chooses max(arr[i],arr[j-1])	
				if (arr[j-1]>arr[i]) {
					y = arr[j]+dp[i][j-2];
				}
				else {
					y =	arr[j]+dp[i+1][j-1];
				}
				dp[i][j] = max(x,y);
			}
		}
		
		s=0;
		for(i=0; i<n; i++) s+=arr[i];
		
		printf("In game %ld, the greedy strategy might lose by as many as %ld points.\n",g, (2*dp[0][n-1])-s); 		
		scanf("%ld",&n);
	}
	return 0;
}		
