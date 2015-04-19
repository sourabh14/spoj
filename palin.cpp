//Palindromes - smallest palin. larger than n
#include<cstdio>
#include<cstring>
#define SIZE 1000006

int t;
char no[SIZE], str[SIZE/2];
long len, mid, i, j, k;

bool greater(char *a, char *b, long l) {
	for (i=0;i<l;i++) {
		if (a[i] == b[i]) continue;
		else return ((a[i]>b[i])?true:false);
	}
	return false;
}		

main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%s",no); 
		len = strlen(no);
		
		if (len & 1) {
			mid = (len/2) + 1;
			for (i=0;i<(mid-1);i++) str[i] = no[mid-2-i];
			str[i] = '\0';
		}
		else {
			mid = len/2;
			for (i=0;i<mid;i++) str[i] = no[mid-1-i];
			str[i] = '\0';
		}	
		
		if (!greater(str,no+mid,i)) {
			for (j=mid-1; (no[j]=='9') && (j>=0); j--) {
				no[j] = '0';
			}
			
			if (j<0) {
				j=0;
				no[mid] = '0'; 
				no[len+1] = '\0';
				len++;
			}	
			
			no[j]++;
		}	
		
		for (i=0,j=len-1; i<j ;i++,j--) no[j] = no[i];
		
		printf("%s\n",no);
	}
}		
