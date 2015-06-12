//Greedy - Kadane's algo variant
#include<cstdio>
#define SIZE 300005

long n, i, l, r, cuml_cost[SIZE];
long long ans, sum_limit, cur_sum;

int main() {
	scanf("%ld %lld",&n, &sum_limit);
	cuml_cost[0] = 0;
	scanf("%ld",&cuml_cost[1]);
	for (i=2; i<=n; i++) { 
		scanf("%ld",&cuml_cost[i]);
		cuml_cost[i] += cuml_cost[i-1];
	}	
	
	ans = 0;
	l=1; r=1;
	while (r<=n) {
		cur_sum = cuml_cost[r] - cuml_cost[l-1];
		if (cur_sum <= sum_limit) {
			if (cur_sum > ans) ans = cur_sum;
			r++;
		}
		else l++;
	}
	
	printf("%lld\n",ans);
	return 0;
}		
				
			
	
				
