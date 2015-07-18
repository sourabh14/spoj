//Strongly connected components
#include <cstdio>
#include <vector>
#include <cstring>

#define MAXN 5003			//maximum number of vertices
using namespace std;

int n, i, j, e, a, b, toplist[MAXN], topn, compn, comp[MAXN];	
vector<int> g[MAXN], g_tran[MAXN];		//g_tran is transpose graph
bool discovered[MAXN], sink[MAXN];


void init1() {		//clear previous graph entries
	for (i=0; i<n; i++) {  
		g[i].clear();
		g_tran[i].clear();
	}	
}

void init2() {		//initialize for graph traversal		
	memset(discovered, 0, sizeof discovered);
	topn = n-1;
}

	
void dftrav(int u) {
	discovered[u] = true;
	for (unsigned int v=0; v<g[u].size(); v++) {		//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
		}	
	}									
	toplist[topn--] = u;				
}


//dfs on transpose graph
void dftrav_t(int u, int c) {
	discovered[u] = true;
	comp[u] = c;
	for (unsigned int v=0; v<g_tran[u].size(); v++) {		//for every undiscovered vertex m connected to u
		int m = g_tran[u][v];
		if (!discovered[m]) {							
			dftrav_t(m, c);									//dftrav m
		}	
	}													
}		


int main() {
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d", &e);			//scan no of vertices and edges
		init1();
		while (e--) {
			scanf("%d %d", &a, &b);		//a and b are vertex no (1 based indexing)
			g[a-1].push_back(b-1);
			g_tran[b-1].push_back(a-1);
		}
		
		init2();					
		for (i=0; i<n; i++) {
			if (!discovered[i]) {
				dftrav(i);
			}
		}	
		
		//Transpose graph
		init2();
		compn = 0;
		for (i=0; i<n; i++) {
			if (!discovered[toplist[i]]) {
				dftrav_t(toplist[i], compn);		//dfs on transpose graph
				sink[compn++] = true;
			}	
		}
		
		for (i=0; i<n; i++) {
			for (j=0; j<g[i].size(); j++) {
				if (comp[i] != comp[g[i][j]]) {		
					//if edge exist between comp of i and comp of g[i][j]
					//then comp[i] is not sink
					sink[comp[i]] = false;
				}	
			}
		}
		
		for (i=0; i<n; i++) {
			if (sink[comp[i]]) {
				printf("%d ",i+1);
			}
		}
		printf("\n");				
		scanf("%d", &n);
	}	
	return 0;
}	

