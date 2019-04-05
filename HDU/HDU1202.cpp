#include "pch.h"
using namespace std;

int calGP(int grade){
    if (grade<60) return 0;
    else if (grade <70) return 1;
    else if (grade <80) return 2;
    else if (grade <90) return 3;
    return 4;
}
int main(){
    int n;
    while (~scanf("%d",&n)){
        // int sum=0,gr,po,sumpo=0;
        double sum=0,sumpo=0,gr,po;
        for(int  i = 0; i < n; i++)
        {
            // scanf("%d%d",&po,&gr);
            scanf("%lf%lf",&po,&gr);
            if (gr==-1) continue;
            sum+=po*calGP(gr);
            sumpo+=po;
        }
        // cout<<sum<<endl;
        if (sumpo!=0) printf("%.2lf\n",1.0*sum/sumpo);
        else
        {
             printf("-1\n");
        }
        
        
    }
}