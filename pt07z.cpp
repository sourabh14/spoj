// BFS - maximum distance between two nodes in a tree
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define VER 10020

using namespace std;

int n, a, b, i, source, dist[VER], mx;
bool visit[VER], discovered[VER];
queue<int> que;
vector<int> g[VER];

void bftrav(int s) {							
	memset(visit,0,n);
	memset(discovered,0,n);			
	
	visit[s-1] = 1;
	dist[s-1] = 0;
	que.push(s-1);
	
	while (!que.empty()) {
		int u = que.front(); 
		que.pop();	
		discovered[u]=1;
		for (int v=0; v<g[u].size(); v++) {					//for every vertex connected to u
			if (!discovered[(g[u][v])]) {
				discovered[(g[u][v])] = 1;
				dist[(g[u][v])] = dist[u] + 1;
				que.push(g[u][v]);
			}	
		}	
		visit[u] = 1;
	}	
}	

void join(int a, int b) {
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);			
}	

int main() {
	scanf("%d", &n);

	for (i=0; i<n-1; i++) {
		scanf("%d %d",&a, &b);
		join(a,b);
	}	
	
	source = 1;
	bftrav(source);
	
	mx = dist[0];
	for (i=1; i<n; i++) {
		if (mx < dist[i]) {
			mx = dist[i];
			source = i+1;
		}	
	}
	
	bftrav(source);
	
	mx = dist[0];
	for (i=1; i<n; i++) {
		if (mx < dist[i]) mx = dist[i];
	}
		
	printf("%d\n",mx);	
	
	return 0;
}	
