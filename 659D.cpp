#include<bits/stdc++.h>

using namespace std;

#define ll int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n;
    cin>>n;

    vector<ll> x(n+1),y(n+1);

    for(ll i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }

    ll ans=0;

    for(ll i=0;i<n-1;i++){
        if(x[i]==x[i+1] && x[i+1]<x[i+2])
            ans+=y[i+1]<y[i];

        else if(x[i]==x[i+1] && x[i+1]>x[i+2])
            ans+=y[i+1]>y[i];

        else if(y[i]==y[i+1] && y[i+1]<y[i+2])
            ans+=x[i+1]>x[i];

        else if(y[i]==y[i+1] && y[i+1]>y[i+2])
            ans+=x[i+1]<x[i];
    }

    cout<<ans<<endl;

    return 0;
}
