#include "pch.h"
using namespace std;
int main(){
    int n,x,y,z;
    while(cin>>n){
        bool flag=0;
        for (x=1;x<=100;x++){
            for (y=1;y<=100;y++){
                for (z=1;z<=100;z++)
                    if (x*x + y*y + z*z == n){
                        flag=1;
                        break;
                    }
                if (flag) break;
            }
            if (flag) break;
        }
        printf("%d %d %d\n",x,y,z);
    }
}