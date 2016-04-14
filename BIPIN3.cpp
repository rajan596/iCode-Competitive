#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

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

    return ans;
}

int main(){

    T {
        ll n,k;
        cin>>n>>k;
        ll ans=(k*binpow(k-1,n-1))%mod;

        if(ans>=0)
            cout<<ans<<endl;
        else
            cout<<"0"<<endl;
    }

    return 0;
}
