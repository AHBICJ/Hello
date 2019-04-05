#include "pch.h"
using namespace std;
int main(){
    long long t;
    scanf("%lld",&t);
    while (t--){
        long long n;
        scanf("%lld",&n);
        long long sum=0,tmp,Max=-1;
        for (long long i=0;i<n;i++){
            scanf("%lld",&tmp);
            Max=max(Max,tmp);
            sum+=tmp;
        }
        if (Max<=sum-Max+1) printf("Yes\n");
        else printf("No\n");
    }
}