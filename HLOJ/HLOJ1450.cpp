#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int sum=0;
        int rmin = (n-m)/2;
        int rmax = rmin+m;
        int tmp;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin>>tmp;
                if (i>=rmin && j>=rmin && i<rmax && j<rmax) sum+=tmp;
            }
        }
        cout<<sum<<endl;
    }
}