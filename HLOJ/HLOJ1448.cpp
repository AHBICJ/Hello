#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int sum=0;
        cin>>n;
        int tmp;
        for (int i=0;i<n;i++) {
            cin>>tmp;
            if (tmp %2==1) sum+=tmp;
        }
        cout<<sum<<endl;
    }
}
