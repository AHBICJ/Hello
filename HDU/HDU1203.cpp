#include "pch.h"
using namespace std;
double dp[10005];
int cost[10005];
double weight[10005];
int main(){
    int n,m;
    while (scanf("%d %d",&n,&m) && !(n==0 &&m==0) ){
        for (int i=0;i<m;i++){
            scanf("%d %lf",&cost[i],&weight[i]);
            weight[i]=1.0-weight[i];
        }
        for (int i=0;i<=n;i++) dp[i]=1.0;
        for (int i=0;i<m;i++){
            for (int j=n;j>=cost[i];j--){
                dp[j]=min(dp[j],dp[j-cost[i]]*weight[i]);
            }
        }
        printf("%.1lf%%\n",100.0*(1.0-dp[n]));
    }
}