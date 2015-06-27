//adhoc
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#define MAX2N 100005
using namespace std;

int n, i, j;
char row1[MAX2N], row2[MAX2N];
pair<int, char> cnt[4];
bool b1, b2;

void insertion_sort(int x) {
	while ((cnt[x].first < cnt[x+1].first) && x<3) {
		swap(cnt[x], cnt[x+1]);
		x++;
	}	
}		

int main() {
	scanf("%d %s",&n, row1);
	
	for (i=0; i<4; i++) {
		cnt[i].first = 0;
		cnt[i].second = i + 'A';
	}	
	for (i=0; i<(n<<1); i++)  cnt[row1[i]-'A'].first++;
	
	for (i=0; i<4; i++) cnt[i].first = n - cnt[i].first;
	
	sort(cnt, cnt+4);
	swap(cnt[0], cnt[3]); swap(cnt[1], cnt[2]);

	if (row1[0] == cnt[0].second) j=1;
	else j=0;
	
	row2[0] = cnt[j].second;
	cnt[j].first--;
	insertion_sort(j);

	for (i=1; i<(n<<1); i++) {
		j=0;
		if ((row1[i] == cnt[j].second) || (row2[i-1] == cnt[j].second)) j++;
		if ((row1[i] == cnt[j].second) || (row2[i-1] == cnt[j].second)) j++;
		
		row2[i] = cnt[j].second;
		cnt[j].first--;
		insertion_sort(j);
	}		
	row2[(1<<n)] = '\0';
	printf("%s\n",row2);
	return 0;
}	
