#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

ll h[100005],r[100005];
ll n,w,l;

bool f(ll x) {
    ll ww=0;

    for(ll i=0;i<n;i++){
        ll q=h[i]+x*r[i];
        if(q>=l) ww+=q;
        if(ww>=w) break;
    }
    return ww>=w;
}

int main(){

    cin>>n>>w>>l;

    for(ll i=0;i<n;i++) {
        cin>>h[i]>>r[i];
    }

    ll L=0,R=1e18;
    ll ans=0;
    if(f(0)){
        cout<<0<<endl;
        return 0;
    }

    while(L<=R) {
        ll mid=(L+R)/2;
        if(f(mid)) {
            ans=mid;
            R=mid-1;
        }
        else {
            L=mid+1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
