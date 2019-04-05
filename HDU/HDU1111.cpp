#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int br, bi, denominator;
bool flag;
int a[105],cnt;
void dfs(int xr,int xi, int n) {
	if (n > 100) return;
	if (xr == 0 && xi == 0) {
		flag = true;
		cnt = n;
		return;
	}
	// X=a0+(a1+(a2+(a3...)*b)*b)*b
	// x's real part minus ai then divided by b
	for (int ai = 0; ai*ai < denominator; ai++) {
		// (a+bi)/(c+di) == (ac+bd)/(c^2+d^2)+(bc-ad)i/(c^2+d^2)
		int x = (xr - ai)*br + xi * bi;
		int y = xi * br - (xr - ai)*bi;
		if (x%denominator == 0 && y%denominator == 0) {
			a[n] = ai;
			dfs(x / denominator,y / denominator,n + 1);
		}
		if (flag) return;
	}
}
int main() {
	int t, xr, xi;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &xr, &xi, &br, &bi);
		// (a+bi)/(c+di) == (ac+bd)/(c^2+d^2)+(bc-ad)i/(c^2+d^2)
		// demoniator == c^2+d^2;
		denominator = br * br + bi * bi;
		flag = false;
		dfs(xr,xi,0);
		if(!flag)
            cout<<"The code cannot be decrypted."<<endl;
        else
        {
            cout<<a[cnt-1];
            for(int i=cnt-2;i>=0;i--)
                cout<<','<<a[i];
            cout<<endl;
		}
		// if (!flag) {
		// 	printf("The code cannot be decrypted.\n");
		// }
		// else {
		// 	for (int i = cnt - 1; i > 0; i--) printf("%d,", a[i]);
		// 	printf("%d\n", a[0]);
		// }
	}
	return 0;
}