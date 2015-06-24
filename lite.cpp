//Segment tree - lazy propagation
#include <cstdio>
#include <algorithm>
#include <cstring>
#define TREESIZE 400000
#define SIZE 100005
using namespace std;

int t, choice;
long segtree[TREESIZE];
bool lazy[TREESIZE];
long n, c, i;
long st, nd;				//for range sum and range update query		

//					-- RANGE SUM --

long rangeSum(long l, long r, long idx) {
	if (lazy[idx]) {								//if lazy node
		segtree[idx] = (r-l+1) - segtree[idx];
		
		if (l != r) {								//not a leaf node
			lazy[(idx<<1) + 1] = !lazy[(idx<<1) + 1];		//switch children's status
			lazy[(idx<<1) + 2] = !lazy[(idx<<1) + 2];
		}
		
		lazy[idx] = 0;								//reset it
	}
	
	if (l>nd || r<st) return 0;						//fully outside
	
	if (l >= st && r <= nd) return segtree[idx];	//fully inside
	
	long mid = (l+r)/2;								//partial 
	return rangeSum(l, mid, ((idx<<1) + 1)) + 
			rangeSum(mid+1, r, ((idx<<1) + 2));
}	


//					-- RANGE UPDATE --
void update_rsq(long l, long r, long idx) {
	if (lazy[idx]) {								//if lazy node
		segtree[idx] = (r-l+1) - segtree[idx];
		
		if (l != r) {								//not a leaf node
			lazy[(idx<<1) + 1] = !lazy[(idx<<1) + 1];		//switch children's status
			lazy[(idx<<1) + 2] = !lazy[(idx<<1) + 2];
		}
		
		lazy[idx] = 0;								//reset it
	}		
	
	
	if (l>nd || r<st) return; 						//fully outside
	
	if (l >= st && r <= nd)  {						//fully inside
		segtree[idx] = (r-l+1) - segtree[idx];
		if (l != r) {								//not a leaf node
			lazy[(idx<<1) + 1] = !lazy[(idx<<1) + 1];		//switch children's status
			lazy[(idx<<1) + 2] = !lazy[(idx<<1) + 2];
		}
		return;
	}
		
	long mid = (l+r)/2;
	update_rsq(l, mid, ((idx<<1) + 1));
	update_rsq((mid + 1), r, ((idx<<1) + 2));
	
	segtree[idx] = segtree[(idx<<1) + 1] + segtree[(idx<<1) + 2];	
}				
	
	
int main() {
	memset(segtree,0,sizeof(segtree));
	memset(lazy,0,sizeof(lazy));
	scanf("%ld %ld", &n, &c);
	while (c--) { 
		scanf("%d",&choice);
		if (choice == 0) {			//range update query
			scanf("%ld %ld",&st, &nd);
			st--; nd--;
			update_rsq(0,n-1,0);	
		}
		else { 						//range sum query
			scanf("%ld %ld",&st, &nd);
			st--; nd--;
			printf("%ld\n",rangeSum(0,n-1,0));
		}	
	}
	return 0;		
}	
