//BFS on matrix
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define INF 1000

int t, n, m, i, j, dist[190][190], wh_px[40000][2], wp, k;
char pixel[190][190];

void print() {
	for (k=0; k<n; k++) {
		for (j=0; j<m; j++) {
			printf("%d ",dist[k][j]);	
		}
		printf("\n");
	}	
	printf("\n");
}	

void bftrav(int x, int y) {				
	queue<int> que;			
	int d;
	
	que.push(x); que.push(y);
	
	//cout << endl << "bf traversal : ";	
	
	while (!que.empty()) {
		int i = que.front();
		que.pop();	
		int j = que.front(); 
		que.pop();	
		
		d = dist[i][j]+1;								//for every pixel connected to (i,j)
		//printf("i : %d j : %d  d : %d\n",i,j,d);		//add to queue only if distance is smaller than current
		//left
		if (j-1>=0 && d<dist[i][j-1]) {
			que.push(i); que.push(j-1);
			dist[i][j-1]=d;
		}	
		//right
		if (j+1<m && d<dist[i][j+1]) {
			que.push(i); que.push(j+1);
			dist[i][j+1]=d;
		}	
		//up
		if (i-1>=0 && d<dist[i-1][j]) {
			que.push(i-1); que.push(j);
			dist[i-1][j]=d;
		}	
		//down
		if (i+1<n && d<dist[i+1][j]) {
			que.push(i+1); que.push(j);
			dist[i+1][j]=d;
		}	
	}
}	

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n, &m);
		for (i=0; i<n; i++) scanf("%s",pixel[i]);
		
		//store every white pixel in array
		
		wp=0;
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (pixel[i][j] == '0') dist[i][j]=INF;
				else {
					dist[i][j]=0;
					wh_px[wp][0]=i;
					wh_px[wp++][1]=j;
				}	
			}
		}
		
		
		//do bfs for every white pixel
		
		for (i=0; i<wp; i++) {
			bftrav(wh_px[i][0],wh_px[i][1]);
		}	
		
		print();
	}	
	return 0;
}			
