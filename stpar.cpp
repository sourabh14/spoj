#include <cstdio>
#include <cstring>
int n, i, arr[1005], stack[1005], cnt, top;

int main() {
	scanf("%d",&n);
	while (n != 0) {
		for (i=0; i<n; i++) scanf("%d",&arr[i]);
		
		memset(stack,0,sizeof(stack));
		cnt = 1; top = 0;
		
		for (i=0; i<n; ) {	
			if (arr[i] == cnt) {	//park it		
				cnt++; i++;
			}	
			else if (stack[top] == cnt) {	//take from stack
				top--;
				cnt++;
			}
			else {						//put in stack
				stack[++top] =	arr[i];
				i++;
			}
		}	
		
		for (; top>0; top--,cnt++) {
			if (stack[top] != cnt) break;
		}
		
		if (top == 0) printf("yes\n");
		else printf("no\n");	
		
		scanf("%d",&n);
	}	
	return 0;
}	
