//connected components in graph
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 100000			
using namespace std;

int n, i, e, a, b, t, connected_comp;
vector<int> g[MAXN];
bool discovered[MAXN];				
	
	
void dftrav(int u) {
	discovered[u] = 1;
	for (unsigned int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
		int m = g[u][v];
		if (!discovered[m]) {							
			dftrav(m);									//dftrav m
		}	
	}				
}	

int main() {
	scanf("%d", &t);
	while (t--) { 
		scanf("%d %d",&n ,&e);			//scan no of vertices and edges
		
		for (i=0; i<n; i++) g[i].clear();
		memset(discovered, 0, sizeof(discovered));
		
		while (e--) {
			scanf("%d %d", &a, &b);		
			g[a].push_back(b);
			g[b].push_back(a);	
		}
		
		connected_comp = 0;
		for (i=0; i<n; i++) {
			if (!discovered[i]) {
				dftrav(i);
				connected_comp++;
			}
		}
		
		printf("%d\n", connected_comp);		
	}	
	return 0;
}	
