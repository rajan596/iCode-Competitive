#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n;
    cin>>n;

    map<ll,ll> mp;
    ll sum=0;
    ll ans=n-1;
    for(ll i=0;i<n;i++) {
        ll t;
        cin>>t;

        sum+=t;
        mp[sum]++;
        ans=min(ans,n-mp[sum]);
    }

    cout<<ans<<endl;

    return 0;
}
