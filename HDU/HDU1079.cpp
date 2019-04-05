#include "pch.h"
#pragma warning (disable:4996)

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
//一.判断奇偶性：（代码量少，但较难想通其正确性）
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	int year, month, day;
	int T, sum;
	cin >> T;
	while (T--) {
		cin >> year >> month >> day;
		sum = month + day;
		if (!(sum & 1) || month == 9 && day == 30 || month == 11 && day == 30)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
*/

/*
评论区其他大神有详细解释，在此就不再赘述。

————————————————————————————————————————————————————————————————————————
二.dfs爆搜（思路直接，正确性一目了然）
#include <bits/stdc++.h>
using namespace std;
int date[500][20][40];
int mon[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31} };
int isleap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}
int dfs(int yy, int mm, int dd) {
	if (date[yy][mm][dd] != -1)
		return date[yy][mm][dd];
	if (yy > 101)
		return 0;
	int y = yy, m = mm, d = dd + 1;
	if (d > mon[isleap(y)][m]) {
		d = 1;
		m++;
	}
	if (m > 12) {
		m = 1;
		y++;
	}
	if (dfs(y, m, d) == 0) {
		date[yy][mm][dd] = 1;
		return 1;
	}

	y = yy, m = mm + 1, d = dd;
	if (m > 12) {
		m = 1;
		y++;
	}
	if (mon[isleap(y)][m] >= d) {
		if (dfs(y, m, d) == 0) {
			date[yy][mm][dd] = 1;
			return 1;
		}
	}
	date[yy][mm][dd] = 0;
	return 0;
}
int main() {
	int T, year, month, day, i;
	memset(date, -1, sizeof(date));
	date[101][11][4] = 0;
	for (i = 5; i <= mon[0][11]; i++)
		date[101][11][i] = 1;
	for (i = 1; i <= mon[0][12]; i++)
		date[101][12][i] = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &year, &month, &day);
		year -= 1900;
		if (dfs(year, month, day))
			printf("YESn");
		else
			printf("NOn");
	}
	return 0;
}

————————————————————————————————————————————————————————————————
方法三.预处理打表，利用必胜点和必败点的性质。（思路更加直接粗暴）
*/
//#include <bits/stdc++.h>
using namespace std;
int sg[500][20][40];
int mon[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31} };
int isleap(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}
void f() {
	int i, j, z, t, y1, m1, d1, y2, m2, d2;
	memset(sg, -1, sizeof(sg));
	sg[101][11][4] = 0;
	for (i = 5; i <= mon[0][11]; i++) sg[101][11][i] = 1;
	for (i = 1; i <= mon[0][12]; i++) sg[101][12][i] = 1;
	j = 11;
	z = 3;
	for (i = 101; i >= 0; i--) {
		if (j <= 0)
			j = 12;
		for (; j > 0; j--) {
			if (z <= 0)
				z = mon[isleap(i)][j];
			for (; z > 0; z--) {
				y1 = i, m1 = j + 1, d1 = z;
				y2 = i, m2 = j, d2 = z + 1;
				if (d2 > mon[isleap(i)][m2]) {
					d2 = 1;
					m2++;
				}
				if (m2 > 12) {
					m2 = 1;
					y2++;
				}
				if (m1 > 12) {
					m1 = 1;
					y1++;
				}
				if (z <= mon[isleap(y1)][m1]) {
					if (sg[y1][m1][d1] && sg[y2][m2][d2])
						sg[i][j][z] = 0;
					else {
						sg[i][j][z] = 1;
					}
				}
				else {
					sg[i][j][z] = !sg[y2][m2][d2];
				}
			}
		}
	}
}
int main() {
	f();
	int T, year, month, day;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &year, &month, &day);
		year -= 1900;
		if (sg[year][month][day] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
