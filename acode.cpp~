//DP
#include<cstdio>
#include<stdint.h>
#include<cstring>

char st[5005];
int le, i, no;
long long ans, prev, temp;

int main() {
	scanf("%s",st);
	while (st[0] != '0') {
		le = strlen(st);
		if (le == 1) {
			printf("1\n");
		}
		else {	
			for (i=0;i<le;i++) st[i] -= '0';
			
			prev = 1;
			if (st[1] > 0) {
				no = st[0]*10 + st[1];
				if (no < 27 && no > 9) ans = 2;
				else ans = 1;
			}
			else {	
				ans = 1;
			}	
			
			for (i=2 ; i<le ; i++) {
				if (st[i] > 0) {
					no = st[i-1]*10 + st[i];
					temp = ans;
					if (no < 27 && no > 9) ans += prev;
					prev = temp;
				}
				else {
					temp = prev;
					prev = ans;
					ans = temp;
				}		
			}
			
			printf("%lld\n",ans);
		}
		scanf("%s",st);
	}
	return 0;
}			
