#include<cstdio>

int t, base; 
long exp;

int modpow(int base) {
	int result = 1;
	while (exp>0) {
		if (exp & 1) result = (result * base)%10;
		base = (base*base)%10;
		exp >>= 1;
	}
	return result;
}		
			
int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %ld",&base, &exp);
		printf("%d\n",modpow(base%10));
	} 
	return 0;
}
