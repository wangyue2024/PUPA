#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =5.1e5;
#define P pair<int,int>
vector<P>e[N];
struct Node
{
    int x,y,c,id;
}a[N];
bool cmpx(Node a,Node b){
    return a.x<b.x;
}bool cmpid(Node a,Node b){
    return a.id<b.id;
}
int n;
void add(int u,int v,int c){e[u].push_back({v,c});}
void build(int base){
    #define in(id) (base+n+id)
    #define out(id) (base+n*2+id)
    for(int i=1;i<=n;++i){
        int u=a[i].id;
        add(in(u),u,0);
        add(u,out(a[i].id),0);
        if(i!=n){
            if(a[i].c==a[i+1].c){
                add(in(a[i].id),in(a[i+1].id),a[i+1].x-a[i].x);
                add(in(a[i+1].id),in(a[i].id),a[i+1].x-a[i].x);
                add(out(a[i].id),out(a[i+1].id),a[i+1].x-a[i].x);
                add(out(a[i+1].id),out(a[i].id),a[i+1].x-a[i].x);
            }
            else{
                add(out(a[i].id),in(a[i+1].id),a[i+1].x-a[i].x);
                add(out(a[i+1].id),in(a[i].id),a[i+1].x-a[i].x);
            }
        }
    }
}
int dis[N];
void dij(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    priority_queue<P,vector<P>,greater<P>>q;
    q.push({0,1});
    while(!q.empty()){
        auto [d,u]=q.top();q.pop();
        if(d>dis[u])continue;
        for(auto [v,c]:e[u]){
            if(dis[v]>d+c){
                dis[v]=d+c;
                q.push({dis[v],v});
            }
        }
    }
}
signed main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].x>>a[i].y>>a[i].c;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmpx);
    build(0);
    for(int i=1;i<=n;++i){swap(a[i].x,a[i].y);}
    sort(a+1,a+n+1,cmpx);
    build(2*n);
    sort(a+1,a+n+1,cmpid);
    dij();
    int ans=1e18;
    for(int i=1;i<=n;++i){
        ans=min(ans,dis[i]+max(abs(a[n].x-a[i].x),abs(a[n].y-a[i].y)));
    }
    cout<<ans<<endl;
}