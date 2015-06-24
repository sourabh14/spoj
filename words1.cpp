//Euler graph
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int t, n, i, in_deg[26], out_deg[26], a, b, c, d;
char str[1003];
vector<int> g[26];
bool discovered[26], node[26], pos;

void init() {
	for (i=0; i<26; i++) g[i].clear();
	memset(in_deg, 0, sizeof(in_deg));
	memset(out_deg, 0, sizeof(out_deg));
	memset(discovered, 0, sizeof(discovered));
	memset(node, 0, sizeof(node));
}		

void join(int a, int b) {			//for undirected graph 
	g[a].push_back(b);
	g[b].push_back(a);			
}

void bftrav(int s) {					
	queue<int> que;		
	discovered[s] = true;
	que.push(s);
	
	while (!que.empty()) {
		int m;
		int u = que.front(); 
		que.pop();	
		for (unsigned int v=0; v<g[u].size(); v++) {					//for every undiscovered vertex m connected to u
			m = g[u][v];
			if (!discovered[m]) {							//push it to que
				discovered[m] = true;
				que.push(m);
			}	
		}	
	}
}	

bool grph_connected() {		//check if graph has a single connected component
	for (i=0; i<26; i++) {
		if (node[i]) break;
	}	
	bftrav(i);
	for (i=0; i<26; i++) {
		if (node[i] && !discovered[i]) {
			return false;
		}
	}
	return true;
}			

int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			scanf("%s",str);
			a = str[0] - 'a';
			b = str[strlen(str)-1] - 'a';
			join(a,b);
			out_deg[a]++; in_deg[b]++;
			node[a] = true; node[b] = true;
		}
		
		pos = false;
		
		if (grph_connected()) {
			c = 0; d = 0;
			for (i=0; i<26; i++) {
				if ((in_deg[i] - out_deg[i]) == 1) c++;
				else if ((out_deg[i] - in_deg[i]) == 1) d++;
				else if (in_deg[i] != out_deg[i]) break;
			}
					
			if (i == 26) {
				if (((c==1) && (d==1)) || ((c+d) == 0)) pos = true;
			}
		}	
		
		if (pos) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");		
	}	
	return 0;
}	

