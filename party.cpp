//DP - 0-1 Knapsack
#include<cstdio>
#include<algorithm>
using namespace std;

int bud, n, fee[105], fun[105], i, j;
int knapsack[105][505], cost, x, y;


int main() {
	scanf("%d %d",&bud, &n);
	while (true) {
		if (bud == 0  &&  n == 0) break;
		
		for (i=0; i<n; i++) scanf("%d %d", &fee[i], &fun[i]);
		
		for (i=0; i<=n; i++) {
			for (j=0; j<=bud; j++) {
				if (i == 0 || j == 0) knapsack[i][j] = 0;
			
				else if (fee[i-1] > j)  knapsack[i][j] = knapsack[i-1][j];
			
				else {
					x = fun[i-1]+knapsack[i-1][j-fee[i-1]];
					y = knapsack[i-1][j];
					knapsack[i][j] = (x>y) ? x : y;	
				}
			}			
		}
	
		for (i=bud,x=knapsack[n][bud]; i>0 ; i--) {
			if (knapsack[n][i] < x) break;
		}
	
		printf("%d %d\n",i+1, knapsack[n][bud]);
		
		scanf("%d %d",&bud, &n);
	}	
	return 0;
}	
