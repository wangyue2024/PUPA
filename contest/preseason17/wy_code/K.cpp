#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =1.1e5;
vector<int>ans;
int ed=0,cnt=0;
int sk[100];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        int a;cin>>a;
        int top=0;
        vector<int>bit;
        while(a)bit.push_back(a&1),a>>=1;
        reverse(bit.begin(),bit.end());
        for(int u:bit){
            while(top>=2&&u<sk[top]){
                u=u-sk[top]+sk[top-1];top-=2;
            }
            if(top==1&&u<sk[top]){
                ed+=u-sk[top];top=0;
            }
            else sk[++top]=u;
            a>>=1;
        }
        for(int i=1;i<=top;++i)ans.push_back(sk[i]);
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    ans.push_back(ed);
    int cnt=0;
    for(int i=0;i<ans.size();++i){
        if(i&1)cnt-=ans[i];
        else cnt+=ans[i];
    }
    cout<<cnt<<endl;


}