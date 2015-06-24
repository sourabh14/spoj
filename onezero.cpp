//BFS, number theory
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 20004
using namespace std;

int t, n, tz, i, que[MAXN], qfront, qrear, parent[MAXN][2], p, j, len;
char ans[MAXN], trzero[MAXN];

void bftrav() {
	if (n == 1) {
		ans[0]='1'; ans[1]='\0';
		return;
	}	
	for (i=0; i<MAXN; i++) parent[i][0]=-1;
	int rem, a;
	char sw;
	qfront=0; qrear=0; que[0] = 1; parent[1][0]=1; parent[1][1]=1;
	
	while (qrear >= qfront) {
		rem = que[qfront++];
		p=rem;
		//check for rem*10						
		rem = (rem<<3) + (rem<<1);
		a = rem % n;
		if (a == 0) {		//number found
			parent[0][0]=p;
			parent[0][1]=0; 
			break;
		}
		else if (parent[a][0] == -1) {
			que[++qrear] = a;
			parent[a][0] = p;
			parent[a][1] = 0;
		}
		
		//check for rem*10 + 1					
		rem++;
		a = rem % n;
		if (a == 0) {		//number found
			parent[0][0]=p;
			parent[0][1]=1; 
			break;
		}
		else if (parent[a][0] == -1) {
			que[++qrear] = a;
			parent[a][0] = p;
			parent[a][1] = 1;
		}		
	}
	
	for (i=0, len=0; parent[i][0]!=1; i=parent[i][0]) {	
		ans[len++] = parent[i][1]+'0';
	}
	ans[len++] = parent[i][1]+'0';
	ans[len++]='1'; ans[len]='\0';
	
	//reverse the ans array
	for (i=0,j=len-1; i<j; i++,j--) {
		sw = ans[i]; ans[i] = ans[j]; ans[j] = sw;
	}		
}			

int main() {
	scanf("%d",&t);
	memset(trzero, '0', sizeof(trzero));
	while (t--) {
		scanf("%d",&n);	
		bftrav();
		printf("%s\n",ans);
		trzero[tz] = '0';
	}
	return 0;
}		
