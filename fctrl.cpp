#include<cstdio>

long t,n,i;
long long ans;

int main() {
	scanf("%ld",&t);
	while (t--) {
		scanf("%ld",&n);
		ans=0;
		for (i=5; i<=n; i*=5) {
			ans += n/i;
		}
		printf("%lld\n",ans);	
	}
	return 0;
}		
