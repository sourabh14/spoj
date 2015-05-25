#include<cstdio>

int t, n, m, i, ans[190][190];
char pixel[190][190];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n, &m);
		for (i=0; i<n; i++) scanf("%s",pixel[i]);
		
