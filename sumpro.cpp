#include <cstdio>
#define MOD 1000000007

long t, n;
unsigned long long l, r, quo, ans, i;

int main() {
	scanf("%ld",&t);
	while (t--) {
		scanf("%ld",&n);
		r=n;
		ans=0;
		for (quo=1; quo*quo<=n; quo++) {
			l=n/(quo+1);
			ans = (ans + ((r-l)*(l+r+1)*quo)/2 ) % MOD;
			r=l;
		}
		for (i=1; i<=l; i++) {
			ans = (ans + (i*(n/i))%MOD)%MOD;
		}	
		printf("%llu\n",ans);	
	}
	return 0;
}		
