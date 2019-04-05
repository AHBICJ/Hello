#include "pch.h"
using namespace std;
int f[26];
bool vis[26];
void Init(){
    for (int i=0;i<26;i++) {f[i]=i;vis[i]=0;}
}

int Find(int x){
    int y=x;
    while(f[y]!=y){
        y=f[y];
    }
    while (f[x]!=y){
        int tmp= f[x];
        f[x]=y;
        x = tmp;
    }
    return y;
}

bool Union(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if (fx==fy) return false;
    f[fx]=fy;
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        Init();
        map<char,int> cnt;
        int n;
        cin>>n;
        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            vis[str[0]-'a']=vis[str[str.size()-1]-'a']=1;
            Union(str[0]-'a',str[str.size()-1]-'a');
            cnt[str[0]]++;
            cnt[str[str.size()-1]]--;
        }
        bool flag=1; int ff=-1;
        for (int i=0;i<26;i++){
            if (vis[i]){
                if (ff==-1) ff=Find(i);
                else if (Find(i)!=ff) {
                    flag=0;break;
                }
            }
        }
        int realSize=0;
        map<char,int>:: iterator it;
        if (flag)
        for (it=cnt.begin();it!=cnt.end();it++){
            if (it->second==0) continue;
            else {
                realSize++;
                if (realSize>2) {flag=0;break;}
                if (it->second!=-1 && it->second!=1) {flag=0;break;}
            }
        }
        if (flag) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    
}
