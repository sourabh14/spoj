/* Lowest common ancestor (LCA) on tree - using DFS and RMQ 
 * DFS on tree : O(n) where n - number of nodes
 * RMQ - restricted - consecutive elements differ by 1  
 * 			algorithmic complexity : Preprocessing - O(n)
 * 								   : Query - O(1)
 *			space complexity : O(n) 
 * 
 * Overall complexity : Preprocessing- O(n)
 * 					  : Query : O(1)
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAXN 1003		//vertices on tree
#define MAXE 2003		//max size of euler tour (dfs) = 2*n - 1
#define MAXLG 12		//ceil(log2(MAXE))

using namespace std;

long t, n, q, i, j, s, cn, ans;
//tree, dfs
bool discovered[MAXN];
vector<int> g[MAXN];
//rmq
long qi, qj, st[MAXE][MAXLG];
//lca
long E[MAXE];		//euler tour
long L[MAXE];		//level of node during euler tour
long H[MAXN], en;	//first occurance of ith node in E


//DFS code ----
void init2() {		//initialize for graph traversal		
	memset(discovered,0,sizeof(discovered));
	memset(H,-1, sizeof(H));
	en=0;			//length of euler tour
}

void dftrav(int u, int lev) {
	discovered[u] = 1;
	if (H[u] == -1) H[u]=en;
	L[en] = lev;
	E[en++]=u;
	for (int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {	
			dftrav(m, lev+1);									//dftrav m
			L[en] = lev;
			E[en++]=u;
			
		}	
	}		
}

//DFS code ----


//RMQ code (On L[i] array) ----

void rmq_precompute() {
	long sz;
	for (i=0; i<en; i++) st[i][0] = L[i];
	
	for (j=1, sz=(1<<j); sz<=en; j++, sz=(1<<j)) {
		for (i=0; i+sz-1<en; i++) {
			st[i][j] = min(st[i][j-1], st[i+(sz>>1)][j-1]);
		}
	}
}			

long rmq_indx(long l, long r) {			//returns index of min value from [l,r]
	int k=0;
	long sz = r-l+1;
	while (sz>>=1) k++;
	
	return min(st[l][k], st[r-(1<<k)+1][k]);
}	

//RMQ code ----

int main() {
	scanf("%ld", &t);
	for (s=1; s<=t; s++) {
		printf("Case %ld\n",s);
		
		//input
		scanf("%ld", &n);
		for (i=0; i<n; i++) {
			scanf("%ld", &cn);
			while (cn--) { 
				scanf("%ld", &j);
				g[i].push_back(j-1);
				g[j-1].push_back(i);
			}
		}		
		
		//dfs
		init2();
		L[0]=0;
		dftrav(0, 0);	
		
		/*
		printf("E : ");
		for (i=0; i<en; i++) printf("%ld ",E[i]+1);
		printf("\n");
		
		printf("L : ");
		for (i=0; i<en; i++) printf("%ld ",L[i]);
		printf("\n");
		*/
		
		
		//rmq
		rmq_precompute();
		
		//query
		scanf("%ld",&q);
		while (q--) {
			scanf("%ld %ld",&qi, &qj);
			qi = H[qi-1]; qj = H[qj-1];
			if (qi > qj) swap(qi, qj);
 			ans = E[rmq_indx(qi, qj)] + 1;
			printf("%ld\n", ans);
			
		}
	}
	return 0;
}			
