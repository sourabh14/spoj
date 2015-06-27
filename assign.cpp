//dp and bitmask
#include <cstdio>
#include <cstring>

int t, n, i, j, p, s;
bool pref[20][20];	//preferance matrix
long long dp[(1<<20)];

int main() {
	scanf("%d",&t);
	while (t--) {
		memset(pref, 0, sizeof pref);
		memset(dp, 0, sizeof dp);
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				scanf("%d",&p);
				if (p) pref[i][j] = 1;
			}
		}
		//s -> set of available subjects
		
		dp[0] = 1;
		for (s=1; s<(1<<n); s++) {	//for all subsets(s) of subjects
			i = __builtin_popcount(s)-1;	//count no of subjects in set
			for (j=0; j<n; j++) {	//for students from 0 to n-1
				if ( !pref[i][j] ) continue;	//if jth subject is not preferred
				if ( !((s>>j)&1) ) continue;	//if jth subject is not present in set
				
				dp[s] += dp[ s & (~(1<<j))];
			}
		}	
			
		printf("%lld\n",dp[s-1]);		
	} 
	return 0;
}				
