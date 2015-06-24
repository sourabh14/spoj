//DFS
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define MAXN 10004	

using namespace std;

int t, n, i, e, a, b, len[MAXN];
vector<int> g[MAXN];
bool discovered[MAXN];
long long ans;

inline void join(int a, int b) {			
	g[a].push_back(b);
	g[b].push_back(a);			
}
					
int dftrav(int u) {
	discovered[u] = 1;
	
	for (unsigned int v=0; v<g[u].size(); v++) {					
		int m = g[u][v];
		if (!discovered[m]) {							
			len[u] += (dftrav(m) + 1);	
		}	
	}				
	len[u]++;
	return len[u];
}	

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d",&n);			
		for (i=0; i<n; i++) g[i].clear();
		memset(discovered, 0, sizeof discovered);
		memset(len, 0, sizeof len);
		
		for (i=0; i<n-1; i++) {
			scanf("%d %d", &a, &b);		
			join(a,b);
		}
		len[0] = dftrav(0);
		ans = 0;
		for (i=0; i<n; i++) {
			ans += len[i];
		}
		printf("%lld\n",ans);	
	}
	return 0;
}	
