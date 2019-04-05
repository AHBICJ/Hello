#include<stdio.h>
#include<string.h>
#define MAX(a,b) (a>b?a:b)
const int MAXN = 1010;
int dp[MAXN][MAXN];
char a[MAXN], b[MAXN];
int main(){
	while (~scanf("%s%s", a + 1, b + 1)){
		memset(dp, 0, sizeof(dp));
		int i, j;
		for (i = 1; a[i]; i++){
			for (j = 1; b[j]; j++){
				if (a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		printf("%d\n", dp[i - 1][j - 1]);
	}
	return 0;
}