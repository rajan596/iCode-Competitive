#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){

    ll n,m;
    cin>>n>>m;

    ll a[n+2];

    for(ll i=0;i<n;i++){
        cin>>a[i+1];
    }

    ll ans=0;
    while(m--){
        ll x,y;
        cin>>x>>y;
        ans+=min(a[x],a[y]);
    }

    cout<<ans<<endl;

    return 0;
}
