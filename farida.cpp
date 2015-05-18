//DP
#include<cstdio>
#include<algorithm>
#define SIZE 10004

using namespace std;

int t;
long n,arr[SIZE],i,j;
long long a,b,c;

int main() {
	scanf("%d",&t);
	for (j=1; j<=t; j++) {
		scanf("%ld",&n);
		for (i=0; i<n; i++) scanf("%ld",&arr[i]);
		
		if (n == 1) printf("Case %ld: %ld\n",j,arr[0]);
		else { 
			a = arr[0]; 
			b = max(arr[0],arr[1]);	
			for (i=2; i<n; i++)	{
				c = b;
				b = max(arr[i]+a, b);
				a = c;
			}	
			printf("Case %ld: %lld\n",j,b);
		}
	}
	return 0;
}					
