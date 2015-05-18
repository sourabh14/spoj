//Segment tree
#include<cstdio>
#include<cstring>
#define SIZE 40004
#define TREESIZE 100005

struct node {
	long op, cl;				//unmatched opening and closing brackets
} segtree[TREESIZE];

typedef struct node NODE;

int t;
long n, m, indx;
char str[SIZE];

//					--CONSTRUCTION--

NODE join(NODE a, NODE b) {
	NODE ret;
	ret.op = b.op + (a.op > b.cl ? (a.op-b.cl) : 0);
	ret.cl = a.cl + (b.cl > a.op ? (b.cl-a.op) : 0);
	return ret;
}	

NODE constructST(long l, long r, long idx) {
	if (l == r) {
		if (str[l] == '(')  segtree[idx].op = 1;
		else segtree[idx].cl = 1;
			
		return segtree[idx];
	}
	
	long mid = (l+r)/2;
	segtree[idx] = join(constructST(l,mid,((idx<<1) + 1)) ,
			constructST(mid+1,r,((idx<<1) + 2)));
		
	return segtree[idx];
}

//							UPDATE

void update(long l, long r, long idx) {		//go upto leaf of tree and modify and in return path join le and ri
	if (l == r && l == indx) {
		if (str[indx] == '(') {
			str[indx] = ')';
			segtree[idx].op--;
			segtree[idx].cl++;
		}
		else {
			str[indx] = '(';
			segtree[idx].op++;
			segtree[idx].cl--;
		} 	
		return;
	}	
	
	long mid = (l+r)/2;
	if (indx <= mid) {		//go to left sub tree
		update(l, mid, ((idx<<1) + 1));
	}
	else {					//go to right sub tree
		update(mid+1, r, ((idx<<1) + 2));
	}		
	
	segtree[idx] = join(segtree[(idx<<1) + 1], segtree[(idx<<1) + 2]);
}	


int main() {
	t=1;
	while (scanf("%ld",&n) == 1) {
		printf("Test %d:\n",t++);
		scanf("%s %ld",str,&m);
		memset(segtree,0,sizeof(segtree));
		
		constructST(0,n-1,0);
		
		while (m--) {
			scanf("%ld",&indx);
			if (indx == 0) {			//check
				if (segtree[0].op == 0  &&  segtree[0].cl == 0) {
					printf("YES\n");
				}
				else printf("NO\n");
			}
			else {	
				indx--;					//update
				update(0,n-1,0);
			}
		}	
	}
	return 0;
}		
		
		
