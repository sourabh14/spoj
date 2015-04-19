//palindromes
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[6500];
int dp[6500][6500];

int minMoves(int l, int r) {
	if (l > r) return 0;
	
	if (str[l] == str[r]) return minMoves(l+1,r-1);
	
	return 1+ min(minMoves(l+1,r) , minMoves(l,r-1));
}	

int main() {
	int t,ans;
	scanf("%d",&t);
	while (t--) {
		scanf("%s",str);
		int len = strlen(str);
		
		
		for (int i=0;i<=len;i++) { dp[i][0] = 0; dp[i][1] = 0; }
		
		for (int j=2 ; j<=len ; j++) {
			for (int i=0 ; i<=len-j ; i++) {
				if (str[i] == str[i+j-1]) dp[i][j] = dp[i+1][j-2]; 
				else dp[i][j] = 1+min(dp[i+1][j-1],dp[i][j-1]); 
			}
		}
		printf("%d\n",dp[0][len]);
	}
	return 0;
}		
