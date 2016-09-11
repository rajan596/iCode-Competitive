#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n,q;
    cin>>n>>q;

    ll a[n+5];
    map<ll,ll> mp;

    for(ll i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }

    sort(a,a+n);

    while(q--) {
        ll t;
        cin>>t;

        string ans="No";

        if(mp[t]) ans="Yes";
        else if(a[0]<t && a[n-1]>t) ans="Yes";

        cout<<ans<<endl;
    }

    return 0;
}
