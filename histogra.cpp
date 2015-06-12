//Stack - Largest rectangle in histogram 
#include<cstdio>
using namespace std;
#define SIZE 100005 

long n, i, arr[SIZE], stack[SIZE], top, t;
long long ans, k, ar;

int main() {
	scanf("%ld",&n);
	while (n != 0) {			
		for (i=0; i<n; i++) {
			scanf("%ld",&arr[i]);
		}
		
		ans = 0;
		i=0;
		top=0;
		while (i<n)	{
			if (top==0 || arr[stack[top]] <= arr[i]) {
				top++;
				stack[top]=i;				//push to stack
				i++;
			}
			else {
				t=stack[top];				//pop it
				top--;
				ar = (long long)arr[t]*(top==0 ? (i):(i-stack[top]-1));
				
				if (ans < ar) ans = ar;
			}
		}		
							//for remaining elements in stack
		
		while (top != 0) {
			t=stack[top];				//pop it
			top--;
			ar = (long long)arr[t]*(top==0 ? (i):(i-stack[top]-1));
			
			if (ans < ar) ans = ar;
		}	
				
		printf("%lld\n",ans);		
		scanf("%ld",&n);
	}
	return 0;
}		
