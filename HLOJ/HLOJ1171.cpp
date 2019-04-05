#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int a[260];
int main(){
	string str;
	while(cin >> str){
		memset(a, 0, sizeof(a));
		for (int i = 0; i < str.size(); i++){
			a[str[i]]++;
		}
		for (int i = 0; i < 260; i++){
			if (a[i]) printf("%c %d\n", i, a[i]);
		}
		printf("\n");
	}
}