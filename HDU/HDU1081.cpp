// HDU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#pragma warning (disable:4996)
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
int a[105][105];
int dp[105];
//求最大子序列和
int cal() {
	int t[105];
	int ans = dp[0];
	t[0] = dp[0];
	for (int i = 1; i < n; i++) {
		t[i]=max(dp[i],t[i-1]+dp[i]);
		ans = max(ans, t[i]);
	}
	return ans;
}
int main()
{
	while (~scanf("%d", &n))
	{
		int tmp;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &tmp);
				a[i][j] = tmp;
			}
		int ans = INT_MIN;
		// 压缩矩阵

		for (int i = 0; i < n; i++) {	// 第i行开始
			memset(dp, 0, sizeof(dp));
			for (int j = i; j < n; j++) {	// 加一行算一行
				for (int k = 0; k < n; k++) {
					dp[k] += a[j][k];
				}
				ans = max(ans, cal());
			}
			// 这儿可以将列方向前缀和，每次后面所有减掉第i行 但是算量相同
		}
		printf("%d\n", ans);
	}
}


