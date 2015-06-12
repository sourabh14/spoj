#include<cstdio>

int main() {
	int g,b,ans;
	scanf("%d %d",&g, &b);
	while (g != -1) {
		if (g==0) ans = b;
		else if (b==0) ans = g;
		else {
			if (g>b) ans = (g/(b+1))+(g%(b+1)==0?0:1);
				
			else ans = (b/(g+1))+(b%(g+1)==0?0:1);
		}
		printf("%d\n",ans);			
		scanf("%d %d",&g, &b);
	}
	return 0;
}		
