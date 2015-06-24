#include<cstdio>

long long sumdig(long long n) { 
	long long m=10, x=n, p=45;
	long long r = x%10;
	long long ret=(r*(r+1))/2;
	
	for (x /= 10; x>0; x /= 10) {
		r = x%10;
		ret += ( p*r + ((m*r*(r-1))/2) + r*((n%m) + 1));
		p = m*(45+p);
		m = (m<<3) + (m<<1);
	}
	return ret;
}		

int main() {
	long  long a, b;
	scanf("%lld %lld",&a, &b);
	while (a != -1) {
		printf("%lld\n",sumdig(b)-sumdig(a-1));
		scanf("%lld %lld",&a, &b);
	}
	return 0;
}		
