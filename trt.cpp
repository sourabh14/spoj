//DP
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n, i, arr[2005];
long dp[2005][2005];

long getmax(int l, int r, int age) {
	if (r<l) return 0;
	
	if (dp[l][r] != -1) return dp[l][r];
	
	long a,b;
	a = age*arr[l] + getmax(l+1,r,age+1);
	b = age*arr[r] + getmax(l,r-1,age+1);
	return dp[l][r] = max(a,b);
}	
	 
int main() {
	scanf("%d",&n);
	for (i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}	
	memset(dp,-1,sizeof(dp));
	printf("%ld\n",getmax(0,n-1,1));
	return 0;
}	
