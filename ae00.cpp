//Number theory
#include<cstdio>

int main() {
	int n, i, ans;
	scanf("%d",&n);
	ans=n;
	for (i=2; i*i<=n; i++) ans += (n/i - i + 1);
	printf("%d\n",ans);
	return 0;
}	
