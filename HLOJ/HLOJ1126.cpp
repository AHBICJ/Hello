#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int main(){
	int t;
	scanf("%d", &t); getchar();
	string s, p;
	while (t--){
		getline(cin, s);
		sort(s.begin(), s.end());
		getline(cin, p);
		sort(p.begin(), p.end());
		//cout << s << "\n" << p << endl;
		if ( s==p )
			printf("Yes\n");
		else
		{
			printf("No\n");
		}
	}
}