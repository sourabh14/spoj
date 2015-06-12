#include<cstdio>

int main() {
	unsigned long long k, ans;
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%lld",&k);
		if (k%2 == 0) ans = ((5*(k/2)-1)*100) + 42;
		else ans = (((5*((k+1)/2))-4)*100) + 92;
		printf("%lld\n",ans);
	}
	return 0;
}	
		
			
