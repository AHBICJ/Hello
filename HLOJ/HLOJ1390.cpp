

#include"pch.h"
#pragma warning (disable:4996)
using namespace std;
int sol[20];
int a[100];
int m, n;
int cnt;
void dfs(int sum, int level, int k) {
	if (sum == m) {
		cnt++;
		for (int i = 0; i < level - 1; i++) printf("%d+", sol[i]);
		printf("%d\n", sol[level - 1]);
		return;
	}
	if (k >= n || sum > m) return;
	for (int i = k; i < n; i++) {
		if (sol[level] == a[i]) continue;
		sol[level] = a[i];
		dfs(sum + a[i], level + 1, i + 1);
	}
}
int main() {
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	while (~scanf("%d%d", &m, &n)) {
		if (n == 0 && m == 0) break;
		printf("Sums of %d:\n", m);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		memset(sol, -1, sizeof(sol));
		cnt = 0;
		dfs(0, 0, 0);
		if (cnt == 0) printf("NONE\n");
	}
	return 0;
}