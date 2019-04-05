#include "pch.h"
#pragma warning (disable:4996)
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if (n==0) {
            cout<<0<<endl;
            continue;
        }
        string ans;
        while(n!=0){
            int tmp = n % m;
            char c;
            if (tmp<10) c = '0'+tmp;
            else c= 'A'+tmp-10;
            n = n/m;
            ans=c+ans;
        }
        cout<<ans<<endl; 
    }
}