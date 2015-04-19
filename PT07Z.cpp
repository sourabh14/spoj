// BFS using N x N matrix 
#include<cstdio>
#include<cstring>
#include<queue>
#define MVER 10004  			//maximum vertices

bool g[MVER][MVER];
bool visit[MVER], discovered[MVER];
long n, u, v, i, dist[MVER];
int source;

void bftrav(int s) {
	queue<int> que;
	memset(visit,0,n);
	memset(discovered,0,n);
	memset(dist,0,n);		
	
	visit[s-1] = 1;
	dist[s-1] = 0;
	que.push(s-1);
	
	while (!que.empty()) {
		long a = que.front(); 
		que.pop();	
		for (long b=0; b<n ;b++) {					//for every vertex connected to u
			if ((g[a][b] == 1) && (visit[b] == 0)) {
				dist[b] = dist[a] + 1;
				que.push(b);
			}	
		}	
		visit[a] = 1;
	}
}

inline void join(long u, long v) {
	g[u-1][v-1] = 1;
	g[v-1][u-1] = 1;			//for undirected graph join both
}

int main() {
	scanf("%ld",&n);
	for (i=0; i<n-1; i++) {
		scanf("%ld %ld",&u, &v);
		join(u,v);
	}	
	source = 1;
	bftrav(source);
	return 0;
}	
