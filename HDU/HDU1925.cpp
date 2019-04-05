//TFoldy.cc
//2007 ECNA

#include <iostream>
using namespace std;

char folds[31];
int repeats, n, l, power, m, x, y;
int Pivot[31], Px[31], Py[31];

void ComputePivot(int p) {
	//cout<<"ComputePivot "<<p;
	char dir = folds[l - p];
	//cout<<" dir="<<dir<<endl;
	if (dir == 'L') {       //pivot (0,0) pi/2 about (Px[p-1], Py[p-1])
		Px[p] = Px[p - 1] + Py[p - 1];
		Py[p] = Py[p - 1] - Px[p - 1];
	}
	else {              // dir=='U' SO, pivot -pi/2
		Px[p] = Px[p - 1] - Py[p - 1];
		Py[p] = Py[p - 1] + Px[p - 1];
	}
}

void PivotXY(int & x, int & y, int p) {
	//pivot (x,y) about (Px[power],Py[power]) in direction folds[power]

  //cout <<"Pivoting ("<<x<<','<<y<<") about ("<<Px[p]<<','<<Py[p]<<") in dir "<<folds[l-p-1]<<endl;
	int delX = x - Px[p], delY = y - Py[p];
	char dir = folds[l - p - 1];
	if (dir == 'L') {       //rotate pi/2
		x = Px[p] - delY; y = Py[p] + delX;
	}
	else {              //dir='U' So rotate -pi/2
		x = Px[p] + delY; y = Py[p] - delX;
	}
	//cout << "     result of pivot: ("<<x<<','<<y<<')'<<endl;
}

void ComputeCoordinates(int m, int power, int & x, int & y) {
	int d, newcorner, newpower;

	//cout<<"   ComputeCoordinates "<<m<<' '<<power<<' ';
	   //  base cases
	if (m == 0) { x = 0; y = 0; }
	else if (m == 1) {                  // m==1
		x = 1; y = 0;
	}
	else {                  //recusrsively backup to find previous point
		d = m - Pivot[power];
		newcorner = Pivot[power] - d;
		newpower = power - 1;
		while (newpower > -1 && Pivot[newpower] > newcorner) newpower--;
		ComputeCoordinates(newcorner, newpower, x, y);
		PivotXY(x, y, power);        //pivot (x,y) about (Px[power],Py[power]) in direction
								 // folds[power]
	}
	//cout<<'('<<x<<','<<y<<')'<<endl;
}

int main() {
	cin >> repeats;
	for (int i = 0; i < repeats; i++) {
		cin >> folds;
		cin >> n;
		l = strlen(folds);
		if (n == 0) cout << "(0,0)" << endl;
		else if (n == 1) cout << "(1,0)" << endl;
		else {
			power = 0;
			Pivot[0] = 1; Px[0] = 1; Py[0] = 0;
			while (Pivot[power] < n && power < l) {
				power++;
				Pivot[power] = Pivot[power - 1] * 2;
				ComputePivot(power);           //get (Px[power], Py[power])
				if (n == Pivot[power]) {        //see if fold is a pivot (power of 2)
					cout << '(' << Px[power] << ',' << Py[power] << ')' << endl;
					power = l + 1;
				}
			}

			if (power != l + 1) {                // fold is not a power of 2
				power--;                       // back off so Pivot[power] < n
				m = n;
				ComputeCoordinates(m, power, x, y);  //corner m pivots about Pivot[power] to
													 // end at (x,y)
				cout << '(' << x << ',' << y << ')' << endl;
			}
		}
	}

	return 0;
}