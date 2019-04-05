#pragma warning (disable:4996)
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 18;
const int YEARDAYS = 365;

int leapyear(int year){
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main(){
	int t, byear, bmonth, bday, sum;
	scanf("%d", &t);
	while (t--){
		scanf("%d-%d-%d", &byear, &bmonth, &bday);
		if (bmonth == 2 && bday == 29) {
			printf("-1\n"); continue;
		}
		sum = 0;
		sum = YEARDAYS * N;
		for (int i = 1; i < N; i++)
			sum += leapyear(byear + i);
		if (bmonth > 2)
			sum += leapyear(byear + N); 
		else sum += leapyear(byear);
		printf("%d\n", sum);
	}
}
