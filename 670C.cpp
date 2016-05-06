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

    ll a[n];
    map<ll,ll> mp;

    for(ll i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }

    int m;
    cin>>m;

    ll b[m],c[m];

    for(ll i=0;i<m;i++) cin>>b[i];
    for(ll i=0;i<m;i++) cin>>c[i];

    ll dp[m],index=0;

    for(int i=0;i<m;i++){
        dp[i]=1e8*mp[b[i]] + 10*mp[c[i]];
        //cout<<i<<" "<<dp[i]<<endl;
        if(dp[index]<dp[i]) {
            index=i;
        }
    }

    cout<<index+1<<endl;

    return 0;
}
