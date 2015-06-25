//inversion count 
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int t, n, i, j, ind, arr[30004];
long long ans;
map<string, int> mp;
char word[30];

void merge(int l, int mid, int r) {
	int n1 = mid-l+1, n2 = r-mid; 
	int arr1[n1], arr2[n2];
	
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
					

void mergeSort(int l, int r) {
	if (l<r) {	
		int mid = (l+r)/2;
		mergeSort(l,mid);
		mergeSort(mid+1,r);
		merge(l,mid,r);
	}
}		

int main() {
	scanf("%d",&t);
	while (t--) {
		ans = 0;
		mp.clear();
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			scanf("%s",word);
			mp.insert(make_pair(word,i));
		}	
		for (i=0; i<n; i++) {
			scanf("%s",word);
			arr[i] = mp[word];
		}	
		mergeSort(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}		
