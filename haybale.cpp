//median, range increment
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1000006
using namespace std;

int n, k, l, r, i, arr[MAXN];

int main() {
	scanf("%d %d",&n, &k);
	memset(arr, 0, sizeof arr);
	while (k--) {
		scanf("%d %d",&l, &r);
		arr[l]++; arr[r+1]--;
	}
	for (i=1; i<n; i++) {
		arr[i] += arr[i-1];
	}		
	partial_sort(arr,arr+((n/2) + 2), arr+n);
	printf("%d\n",arr[(n-1)/2]);
	return 0;
}	
