#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

const ll mod=1e9+7;

ll binpow(ll a,ll b){
    ll ans=1;

    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }

    return ans%mod;
}

ll modInv(ll x){
    return binpow(x,mod-2);
}

int main(){

    ll a,b,n,x;
    cin>>a>>b>>n>>x;

    if(a==1) {
        n=n%mod;
        cout<<(x%mod+(b*n)%mod)%mod<<endl;
        return 0;
    }

    ll an=binpow(a,n);
    x=x%mod;
    an=an%mod;
    ll ans=(x*an)%mod;

    ll p=(b*(an-1))%mod;
    p=p*modInv(a-1);

    ans=(ans+p)%mod;

    cout<<ans<<endl;

    return 0;
}
