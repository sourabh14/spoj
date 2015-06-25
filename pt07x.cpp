//Vertex cover , largest independent set in a tree
#include <cstdio> 
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 100005

int n, i, x, y, dp[MAXN][2];	//dp[i][0]-> i is included in lis; dp[i][1]->i not included
vector<int> g[MAXN];
bool discovered[MAXN];

void init2() {						//initialize for graph traversal		
	memset(dp,0,sizeof(dp));
	memset(discovered,0,sizeof(discovered));
}

void join(int a, int b) {			//for undirected graph 
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);			
}

void dftrav(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g[u].size(); v++) {		//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
			//if u is chosed - it's chldren cannot be chosen
			dp[u][0] += dp[m][1];
			//if u is not chosen - it's children may or may not be chosen
			dp[u][1] += max(dp[m][0], dp[m][1]);
		}	
	}				
	dp[u][0]++;
}	

int main() {
	scanf("%d",&n);
	for (i=0; i<n-1; i++) {
		scanf("%d %d",&x, &y);
		join(x, y);
	}
	init2();
	dftrav(0);
	printf("%d\n",n-max(dp[0][0], dp[0][1]));
	return 0;
}		
