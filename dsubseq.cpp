//dp
#include <cstdio>
#include <cstring>
#define MAXN 100005
#define MOD 1000000007

char str[MAXN];
long long dp[MAXN];
int t, i, n, lo, last_occ[26];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%s",str);
		n = strlen(str);
		
		for (i=0; i<26; i++) last_occ[i] = -1;
		dp[0] = 1;
		for (i=1; i<=n; i++) {
			dp[i] = (dp[i-1]<<1);  
			if (dp[i] > MOD) dp[i] -= MOD;
			lo = last_occ[str[i-1]-'A'] - 1; 
			if (lo >= 0) {
				dp[i] -= dp[lo];
			}	
			if (dp[i] < 0) dp[i] += MOD;
			last_occ[str[i-1]-'A'] = i;
		}
		
		printf("%lld\n",dp[n]);
	}
	return 0;
}			
