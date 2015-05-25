//DP
#include<cstdio>
#include<algorithm>
using namespace std;
#define SIZE 100005 

long n, i, j, mn, arr[SIZE];
long long ans, k;

int main() {
	scanf("%ld",&n);
	while (n != 0) {
		for (i=0; i<n; i++) scanf("%ld",&arr[i]);
		
		ans = 0;
		for (i=0; i<n; i++) {
			mn = arr[i];
			for (j=i; j<n; j++) {
				mn = min(mn,arr[j]);
				k = (long)mn*(j-i+1);
				if (ans < k) ans = k;
			}
		}		
			
		printf("%lld\n",ans);		
		scanf("%ld",&n);
	}
	return 0;
}		
