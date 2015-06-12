#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define MAXN 3002
using namespace std;

long n, e, t, i, j, gender[MAXN], p, gnd, v, m;
vector<long> g[MAXN];
bool visit[MAXN], bugFound;

void join(long u, long v) {
	g[u].push_back(v);
	g[v].push_back(u);			
}

bool bftrav(int source) {
	queue<int> que;
	gender[source] = 0;
	que.push(source);
	
	while (!que.empty()) {
		p = que.front(); 
		visit[p] = true;
		que.pop();	
		gnd = gender[p];
		for (v=0; v<g[p].size(); v++) {					//for every vertex 'm' connected to p
			m = g[p][v];
			if (gender[m] == -1) {
				gender[m] = (gender[p] == 0) ? 1:0;
				que.push(m);
			}	
			else if (gender[m] == gnd) {	
				return true;
			}	
		}	
	}
	return false;	
}		

int main() {
	scanf("%ld",&t);
	for (int s=1; s<=t; s++) {
		memset(gender,-1,sizeof(gender));
		memset(visit,0,sizeof(visit));
		for (i=0; i<MAXN; i++) g[i].clear();	
	
		scanf("%ld %ld",&n, &e);
		while (e--) {
			scanf("%ld %ld",&i, &j);
			join(i,j);
		}
		
		bugFound = false;
		for (i=0; i<n; i++) {
			if (!visit[i]) {
				if (bftrav(i) == true) {
					bugFound = true;
					break;
				}
			}		
		}	
		
		printf("Scenario #%d:\n",s);
		if (bugFound) {
			printf("Suspicious bugs found!\n");	
		}
		else {
			printf("No suspicious bugs found!\n");
		}
			
	}
	return 0;
}			
		
