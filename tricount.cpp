#include<cstdio>

long t;
unsigned long long ans,n;

int main() {
	scanf("%ld",&t);
	while (t--) {
		scanf("%llu",&n);
		if (n%2 == 0) ans=(n*(n+2)*(2*n+1))/8;
		else ans=((n*(n+2)*(2*n+1))-1)/8;
		printf("%llu\n",ans);
	}
	return 0;
}		
