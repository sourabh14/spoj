//Math
#include <cstdio>

long long MOD = (1LL << 32), ans;
long t;
long long l, r;

unsigned long long csum(unsigned long long n) {
	n++;
	unsigned long long pow2, pow3, ret=0, cnt, a;
	for (pow2=2, pow3=1; pow2<=n; pow2<<=1, pow3*=3) {
		a = (n/pow2)*pow2;
		cnt = a/2;
		if ((n-a) > pow2/2) {
			ret = (ret + (cnt * (pow3 % MOD))%MOD ) % MOD;
		}
		ret = ret + (cnt * pow3);
	}
	
	if (n > (pow2/2)) {
		cnt = n - (pow2/2);
		ret = (ret + (cnt * (pow3 % MOD))%MOD ) % MOD;
	}
	
	return ret;
}			
			

int main() {
	scanf("%ld",&t);
	while (t--) {
		scanf("%lld %lld", &l, &r);
		ans = csum(r) - csum(l-1);
		if (ans < 0) ans += MOD;
		printf("%llu\n", ans);
	}
	return 0;
}		
