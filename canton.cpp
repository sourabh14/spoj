#include<cstdio>
#include<cmath>
using namespace std;

int t;
long n, p, a, b;
double k;	

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%ld",&n);
		k = (sqrt((double)8*n) - 1);
		p = ceil(k/2);
		if (p%2 == 0) {
			a = p + n - (p*(p+1))/2;
			b = p + 1 - a;
		}
		else {
			a = 1 + (p*(p+1))/2 - n;
			b = p + 1 - a;
		}
		printf("TERM %ld IS %ld/%ld\n",n,a,b);	
	} 
	return 0;
}				
	

