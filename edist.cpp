#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char str1[2005], str2[2005];
int t, n1, n2, dp[2005][2005], i;

int editdistance() {
	int a, b, c, j;
	for (i=1; i<=n1; i++) {
		for (j=1; j<=n2; j++) {
			a = dp[i-1][j] + 1;		//delete 
			b = dp[i][j-1] + 1;		//insert
			c = dp[i-1][j-1];		
			if (str1[i-1] != str2[j-1]) c++;   //change
			
			dp[i][j] = min(min(a,b),c);
		}
	}
	return dp[n1][n2];
}			

int main() {
	scanf("%d",&t);
	for (i=0;i<2005;i++) {
		dp[0][i] = i;
		dp[i][0] = i;
	}	
	while (t--) {
		scanf("%s %s",str1,str2);
		n1 = strlen(str1);
		n2 = strlen(str2);
		printf("%d\n",editdistance());
	}
	return 0;
}		
