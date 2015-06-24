//BFS on matrix 
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int t, sx, sy, dx, dy, dist[8][8];
bool discovered[8][8];
char c[3];


void init() {
	memset(discovered, 0, sizeof(discovered));
	memset(dist, 0, sizeof(dist));
}	

void bftrav(int x, int y) {
	queue<int> que;
	int a, b, kx, ky, d;
	que.push(x); que.push(y);
	dist[x][y] = 0;
	discovered[x][y] = true;
	
	while (!discovered[dx][dy]) {
		a = que.front(); que.pop();
		b = que.front(); que.pop();
		d = dist[a][b];
		
		//left
		ky = b-2;
		if (ky>=0) {
			kx = a+1;
			if (kx<8 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}
			kx = a-1;
			if (kx>=0 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}	
		}	
		
		//right
		ky = b+2;
		if (ky<8) {
			kx = a+1;
			if (kx<8 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}
			kx = a-1;
			if (kx>=0 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}	
		}	
		
		//up
		kx = a-2;
		if (kx>=0) {
			ky = b+1;
			if (ky<8 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}
			ky = b-1;
			if (ky>=0 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}	
		}	
		
		//down
		kx = a+2;
		if (kx<8) {
			ky = b+1;
			if (ky<8 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;\
			}
			ky = b-1;
			if (ky>=0 && !discovered[kx][ky]) {
				que.push(kx); que.push(ky);
				discovered[kx][ky] = true;
				dist[kx][ky] = d+1;
			}	
		}	
	}	
}			

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%s",c);
		sx = 8 - (c[1]-'0');
		sy = c[0] - 'a';
		scanf("%s",c);
		dx = 8 - (c[1]-'0');
		dy = c[0] - 'a';
		
		init();
		bftrav(sx, sy);
		printf("%d\n",dist[dx][dy]);
		
	}
	return 0;
}		
