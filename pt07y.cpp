//union find - check if an undirected graph is a tree or not 
#include<cstdio>
#include<cstdlib>
#include<set>

using namespace std;

int m,n, v1, v2;
bool b1, b2;


int main() {
	set<int> graph;
	scanf("%d %d",&n, &m);
	
	while (m--) {
		scanf("%d %d",&v1, &v2);
		b1 = (graph.find(v1) == graph.end())?1:0;
		b2 = (graph.find(v2) == graph.end())?1:0;
		if (b1 || b2) {
			graph.insert(v1); 
			graph.insert(v2);
		}	
		else {
			printf("NO\n");
			exit(0);
		}	
	}
	
	printf("YES\n");
	return 0;
}		
