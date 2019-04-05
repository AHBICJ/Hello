#pragma warning (disable:4996)
#include<iostream>
#include<cstring>
#include<string>

using namespace std;
char a[25][50];
int main(){
	string str;
	int n;
	while (cin >> n && n){
		cin >> str;
		memset(a, 0, sizeof(a));
		int flag = 1;
		int idx = 0;
		int jdx = 0;
		for (int i = 0; i < str.size(); i++){
			a[idx][jdx] = str[i];
			idx +=flag;
			if (idx == n){
				jdx++;
				flag = -1;
				idx--;
			}
			if (idx == -1){
				jdx++;
				flag = 1;
				idx++;
			}
		}
		for (int i = 0; i < n; i++) printf("%s", a[i]);
		printf("\n");
	}

}