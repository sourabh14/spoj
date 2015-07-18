//bfs, minimum path  water jug problem
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
#define MAXN 40004

int a, b, c, t, dist[MAXN], x, y, d;
bool visited[MAXN][MAXN];

void bftrav() {					
	memset(dist, -1, sizeof(dist));	
	memset(visited, 0, sizeof visited);	
	
	queue<int> que;		
	dist[0] = 0; 
	dist[a] = dist[b] = 1;
	que.push(0); que.push(0); que.push(0);
	visited[0][0] = true;
	
	while (!que.empty()) {
		x = que.front(); que.pop();
		y = que.front(); que.pop();	
		d = que.front(); que.pop();	
		visited[x][y] = true;
		
		//Empty a vessel
		if (!visited[0][y]) { que.push(0); que.push(y); que.push(d+1); }
		
	 	if (!visited[x][0]) { que.push(x); que.push(0); que.push(d+1); }
		
		//Fill a vessel
		if (!visited[a][y]) { que.push(a); que.push(y); que.push(d+1); }
		
		if (!visited[x][b]) { que.push(x); que.push(b); que.push(d+1); }
		
		//One vessel to another	
			//b to a
		if ((x+y <= a) && (!visited[x+y][0])) {
			que.push(x+y); que.push(0); que.push(d+1); 
			if (dist[x+y] == -1) dist[x+y] = d+1;
		}
		
		if ((x+y >= a) && (!visited[a][x+y-a])) {
			que.push(a); que.push(x+y-a); que.push(d+1); 
			if (dist[x+y-a] == -1) dist[x+y-a] = d+1;
		}
			
			//a to b
		if ((x+y <= b) && (!visited[0][x+y])) {
			que.push(0); que.push(x+y); que.push(d+1); 
			if (dist[x+y] == -1) dist[x+y] = d+1;
		}
		
		if ((x+y >= b) && (!visited[x+y-b][b])) {
			que.push(a); que.push(x+y-a); que.push(d+1); 
			if (dist[x+y-b] == -1) dist[x+y-b] = d+1;
		}
				
		if (dist[c] != -1) break;
	}
}	


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &a, &b, &c);
		bftrav();
		printf("%d\n",dist[c]);
	}
	return 0;
}		
