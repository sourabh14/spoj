//Inversion count - modified merge sort
#include<cstdio>

long t, n, i, j, ind, arr[200005];
long long ans;

void merge(long l, long mid, long r) {
	long n1 = mid-l+1, n2 = r-mid; 
	long arr1[n1], arr2[n2];
	
	for (i=0; i<n1; i++) arr1[i] = arr[l+i];
	for (i=0; i<n2; i++) arr2[i] = arr[mid+i+1];
	
	i=0; j=0; ind=l;
	while (i<n1 && j<n2) {
		if (arr1[i] > arr2[j]) {			//inversion
			arr[ind] = arr2[j];
			ans += (n1-i);
			j++; ind++;
		}
		else {
			arr[ind] = arr1[i];
			i++; ind++;
		}
	}
	
	if (i==n1) {											//arr1 is exhausted
		for (; j<n2; j++,ind++) arr[ind] = arr2[j];		//copy remaining
	}
	else {												//arr2 is exhauste
		for (; i<n1; i++,ind++) arr[ind] = arr1[i];
	}	
}					
					

void mergeSort(long l, long r) {
	if (l<r) {	
		long mid = (l+r)/2;
		mergeSort(l,mid);
		mergeSort(mid+1,r);
		merge(l,mid,r);
	}
}		

int main() {
	scanf("%ld",&t);
	while (t--) {
		ans = 0;
		scanf("%ld",&n);
		for (i=0; i<n; i++) scanf("%ld",&arr[i]);
		mergeSort(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}		
