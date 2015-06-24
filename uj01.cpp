//math
#include <cstdio>

long long t, x, y, xc, yc, n, lcm, in, ans;

long long hcf(long long a, long long b) {
	while (b) {
		long long r = a%b;
		a = b;
		b = r;
	}
	return a;	
}

int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld %lld", &x, &y, &n);
		lcm = (x*y)/hcf(x,y);
		in = (lcm/x) + (lcm/y) - 1;
		ans = (n/in)*lcm;
		xc = ans; yc = ans;
		n -= ((n/in)*in);
		
		while (n--) {
			if ((xc + x) < (yc + y)) {
				xc += x;
				ans = xc;
			}
			else {
				yc += y;
				ans = yc;
			}		
		}
		printf("%lld\n",ans);	
	}
	return 0;
}		
