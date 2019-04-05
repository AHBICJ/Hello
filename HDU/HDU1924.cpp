#include "pch.h"
using namespace std;

int toInt(string s) {
	int res = 0;
	int prev = 0;
	// 因为左边如果小于右边 就要减 倒着来
	for (int i = s.length() - 1; i >= 0; i--) {
		int tmp = 0;
		switch (s[i])
		{
		case 'I' : tmp = 1; break;
		case 'V' : tmp = 5; break;
		case 'X' : tmp = 10; break;
		case 'L' : tmp = 50; break;
		case 'C' : tmp = 100; break;
		case 'D' : tmp = 500; break;
		case 'M' : tmp = 1000; break;
		}
		if (tmp >= prev) res += tmp;
		else res -= tmp;
		prev = tmp;
	}
	return res;
}
string toRoman(int val) {
	string ans = "";
	if (val >= 1000) {
		for (int i = 0; i < val / 1000; i++) ans += "M";
		val %= 1000;
	}
	if (val >= 900) {
		ans += "CM";
		val -= 900;
	}
	if (val >= 500) {
		ans += "D";
		val -= 500;
	}
	if (val >= 400) {
		ans += "CD";
		val -= 400;
	}
	if (val >= 100) {
		for (int i = 0; i < val / 100; i++) ans += "C";
		val %= 100;
	}
	if (val >= 90) {
		ans += "XC";
		val -= 90;
	}
	if (val >= 50) {
		ans += "L";
		val -= 50;
	}
	if (val >= 40) {
		ans += "XL";
		val -= 40;
	}
	if (val >= 10) {
		for (int i = 0; i < val / 10; i++) ans += "X";
		val %= 10;
	}
	if (val >= 9) {
		ans += "IX";
		val -= 9;
	}
	if (val >= 5) {
		ans+="V";
		val -= 5;
	}
	if (val >= 4) {
		ans += "IV";
		val -= 4;
	}
	if (val >= 1) {
		for (int i = 0; i < val / 1; i++) ans += 'I';
		val %= 1;
	}
	return ans;
}
int main() {
	int n, total, icase = 0;
	while (cin>>n && n > 0) {
		icase++;
		total = 0;
		for (int i = 0; i < n; i++) {
			string num;
			cin >> num;
			total += toInt(num);
		}
		cout << "Case " << toRoman(icase) << ": " << toRoman(total) << endl;
	}
}