#include<bits/stdc++.h>
using namespace std;
const int N =110;
vector<int>e[N];
int fa[N],dep[N];
struct ANS
{
    int a,b,c,d;
};
vector<ANS>ans;

void dfs(int u,int pa){
    dep[u]=dep[pa]+1;
    fa[u]=pa;
    for(auto v:e[u])if(v!=pa){
        dfs(v,u);
    }
}
void ER(int a,int b){
    e[a].erase(find(e[a].begin(),e[a].end(),b));
    e[b].erase(find(e[b].begin(),e[b].end(),a));
}
void add(int a,int b){
    e[a].push_back(b);
    e[b].push_back(a);
}
void opt(int a,int b,int c,int d){
    ans.push_back({a,b,c,d});
    ER(a,b);ER(b,c);ER(c,d);
    add(a,c);add(a,d);add(b,d);
    // cerr<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}
int n;
int vis[N];
int findnt(int u,int v){
    return e[u][0]==v?e[u][1]:e[u][0];
}
signed main(){
    int st=0;
    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;add(u,v);
    }
    int u=0;
    for(int i=1;i<=n;++i){
        if(e[i].size()==1){u=i;break;}
    }
    int solve=1;
    vis[u]=1;
    u=e[u][0];
    while(e[u].size()+solve!=n){
        vis[u]=1;
        if(e[u].size()==2){
            solve++;
            u=vis[e[u][0]]?e[u][1]:e[u][0];
            continue;
        }
        else{
            int f1=0,f2=0;
            for(int v:e[u]){
                if(vis[v])continue;
                if(e[v].size()>=2){
                    if(f1==0)f1=v;
                    else f2=v;
                }
                else f2=v;
            }
            int f3=e[f1][0]==u?e[f1][1]:e[f1][0];
            opt(f2,u,f1,f3);
        }
    }
    while(solve>=3){
        solve=solve-3;
        int f2;
        for(int v:e[u])if(vis[v])f2=v;
        int f3=findnt(f2,u),f4=findnt(f3,f2);
        opt(u,f2,f3,f4);
        if(solve<=1)break;
        int f5;
        for(int v:e[f4])if(v!=f2&&v!=u)f5=v;
        int f6=findnt(f5,f4);
        opt(u,f4,f5,f6);
        opt(u,f6,f4,f2);
    }
    int cnt=0;
    // for(int i=1;i<=n;++i)cnt+=(e[i].size()>=2),cout<<e[i].size()<<" ";
    // if(cnt<=2)cout<<"YES";
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it.a<<" "<<it.b<<" "<<it.c<<" "<<it.d<<endl;
    }
    
}