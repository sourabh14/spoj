//Segment tree - max frequency in a range
#include <cstdio>
#include <algorithm>
#define SIZE 100005
#define SEGSIZE 400005

using namespace std;

struct node {			//in segment
	long lmd, lmf;		//left most digit and its freq
	long rmd, rmf;		//right most digit and its freq
	long md, mf;		//max digit and its freq		
};
typedef struct node NODE;

long l, r, i, n, q, x, y, arr[SIZE];
NODE segtree[SEGSIZE], ans;
	

//										Construction
inline NODE join(NODE a, NODE b) {
	NODE ret;
	
	ret.lmd = a.lmd;
	if (a.lmd == b.lmd) ret.lmf = a.lmf + b.lmf; 
	else ret.lmf = a.lmf;
	
	ret.rmd = b.rmd;
	if (a.rmd == b.rmd) ret.rmf = a.rmf + b.rmf; 
	else ret.rmf = b.rmf;
	
	if (a.mf > b.mf) { ret.mf=a.mf; ret.md=a.md; }	
	else { ret.mf=b.mf; ret.md=b.md; }
	
	if (a.rmd == b.lmd) {	
		if (ret.mf < a.rmf+b.lmf) {
			ret.mf = a.rmf+b.lmf;
			ret.md = a.rmd;
		}
	}
			
	return ret;
}	 

NODE constructST(long l, long r, long idx) {
	if (l == r) {
		segtree[idx].lmd = arr[l];
		segtree[idx].rmd = arr[l];
		segtree[idx].md = arr[l];
		segtree[idx].lmf = 1;
		segtree[idx].rmf = 1;
		segtree[idx].mf = 1;
		return segtree[idx];
	}
	
	long mid = (l+r)/2;
	NODE le = constructST(l,mid,((idx<<1) + 1));
	NODE ri = constructST(mid+1,r,((idx<<1) + 2));
	segtree[idx] = join(le, ri);
		
	return segtree[idx];
}		



//										Query

NODE rangeFreq(long l, long r, long idx, long a, long b) {
	if (l == a && r == b) {
		return segtree[idx];	
	}	
	
	long mid = (l+r)/2;
	if (b <= mid) {		//go to left sub tree
		return rangeFreq(l, mid, ((idx<<1) + 1), a, b);
	}
	
	if (a > mid) {		//go to right sub tree
		return rangeFreq(mid+1, r, ((idx<<1) + 2), a, b);
	}		
	
	NODE le = rangeFreq(l, mid, ((idx<<1) + 1), a, mid);
	NODE ri = rangeFreq(mid+1, r, ((idx<<1) + 2), mid+1, b);
	return join(le,ri);
}		


int main() {
	scanf("%ld", &n);
	while (n != 0) { 
		scanf("%ld",&q);
		for (i=0; i<n; i++) scanf("%ld",&arr[i]);
	
		constructST(0,n-1,0);
	
		while (q--) {
			scanf("%ld %ld",&x, &y);
			x--; y--;
			ans = rangeFreq(0,n-1,0,x,y);
			printf("%ld\n",ans.mf);
		}	
		scanf("%ld", &n);
	}	
	return 0;
}		
