//prime no-sieve, bfs
#include<cstdio>
#include<cstring>
#include<queue>

#define HIGH 100000	
#define INF 1000000		 

using namespace std;

bool isprime[HIGH];
int t, i, sor, dest, dist[HIGH];
bool visit[HIGH], discovered[HIGH];

void sieve() {
	long i, j;
	memset(isprime,1,sizeof(isprime));
	isprime[0] = 0;
	isprime[1] = 0;
	for (i=2; i*i<=HIGH; i++) {
		if (isprime[i] == 1) { 				// if it is prime
			for (j=i*2; j<=HIGH; j+=i) {
				isprime[j] = 0;	
			}				
		}
	}
}	

void init2() {		//initialize for graph traversal		
	memset(visit,0,sizeof(visit));
	memset(discovered,0,sizeof(discovered));
	memset(dist,0,sizeof(dist));
}

void bftrav() {					//s is the source	
	init2();		
	queue<int> que;		
	discovered[sor] = true;
	dist[sor] = 0;
	que.push(sor);
	
	while (!que.empty()) {
		int m;
		int u = que.front(); 
		que.pop();	
		visit[u] = 1;
		if (u == dest) break;
		
		//thousand's place
		for (i=1; i<10; i++) {
			m = i*1000 + u%1000;
			if (!discovered[m] && isprime[m]) {							
				discovered[m] = true;
				dist[m] = dist[u] + 1;
				que.push(m);
			}
		}
		
		//hundred's place
		for (i=0; i<10; i++) {
			m = (u/1000)*1000 + i*100 + u%100;
			if (!discovered[m] && isprime[m]) {							
				discovered[m] = true;
				dist[m] = dist[u] + 1;
				que.push(m);
			}
		}
		
		//ten's place
		for (i=0; i<10; i++) {
			m = (u/100)*100 + i*10 + u%10;
			if (!discovered[m] && isprime[m]) {							
				discovered[m] = true;
				dist[m] = dist[u] + 1;
				que.push(m);
			}
		}
		
		//one's place
		for (i=0; i<10; i++) {
			m = (u/10)*10 + i;
			if (!discovered[m] && isprime[m]) {							
				discovered[m] = true;
				dist[m] = dist[u] + 1;
				que.push(m);
			}
		}	
	}
}	

int main() {
	sieve();
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&sor, &dest);
		bftrav();
		printf("%d\n",dist[dest]);
	}	
	return 0;
}		
