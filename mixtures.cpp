//DP - matrix multiplication variant
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;

int n, arr[101], i, j, k, color[101][101], size;
unsigned long long smoke[101][101], a;

void print() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%lld ",smoke[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}			

int main() {
	while (scanf("%d",&n)!=-1) {
		for (i=0; i<n; i++) {
			scanf("%d",&arr[i]);
			color[i][i]=arr[i];
			smoke[i][i]=0;
		}	
		
		//calculate color for each range i to j
		
		for (i=0; i<n-1; i++) {
			for (j=i+1; j<n; j++) {
				color[i][j] = (arr[j]+color[i][j-1])%100;
				smoke[i][j] = ULLONG_MAX;
			}
		}
		
		//calculate smoke
		
		for (size=2; size<=n; size++) {
			for (i=0,j=i+size-1; j<n; i++,j++) {
				for (k=i; k<j; k++) {
					a=(smoke[i][k] + smoke[k+1][j] + color[i][k]*color[k+1][j]);
					smoke[i][j] = min(smoke[i][j], a);
				}
			}
		}
		printf("%llu\n",smoke[0][n-1]);
	}
	return 0;
}				
					
