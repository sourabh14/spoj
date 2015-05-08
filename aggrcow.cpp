#include<cstdio>
#include<algorithm>
#define SIZE 100005
using namespace std;

int t;
long cowpos[SIZE], c , n, i;

bool leastsize(long x) {
	long ncow=1, lastpos=cowpos[0];
	for (i=1; i<n; i++) {
		if (cowpos[i]-lastpos >= x) {
			ncow++;
			lastpos = cowpos[i];
			if (ncow == c) return true;
		}
	}
	return false;
}	 	

long binsearch() {
	long st, end, mid;
	st = 0; end = cowpos[n-1];
	while (st < end) {
		mid = (st+end)/2;
		
		if (leastsize(mid)) {
			st = mid+1;
		}
		else {
			end = mid;
		}		
	}	
	return st-1;
}	

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%ld %ld",&n,&c);
		for (i=0; i<n; i++) scanf("%ld",&cowpos[i]);
		
		sort(cowpos, cowpos+n);
		printf("%ld\n",binsearch());
	}
}		
