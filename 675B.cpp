#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;

    ll v[4];
    ll ans=0;
    for(ll i=1;i<=n;i++){
        v[0]=a+b+1+i;
        v[1]=d+b+1+i;
        v[2]=c+d+1+i;
        v[3]=a+c+1+i;
        sort(v,v+4);
        ll a1=v[3];

        v[0]=a+b+n+i;
        v[1]=d+b+n+i;
        v[2]=c+d+n+i;
        v[3]=a+c+n+i;
        sort(v,v+4);
        ll a2=v[0];

        //cout<<a1 <<" "<<a1<<endl;
        if(a2-a1+1>0)
            ans+=a2-a1+1;
    }
    cout<<ans<<endl;
    return 0;
}
