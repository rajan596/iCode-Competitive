#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long int
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

ll a[100005],b[100005];
ll n,k;

ll f(ll mid) {
    ll t=0;
    for(ll i=0;i<n;i++) {
        t+=max((ll)0,mid*a[i]-b[i]);
        if(t>k){
            t=k+1;
            break;
        }
    }
    return t;
}

int main(){

    cin>>n>>k;

    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];

    ll l=1,r=1e9;
    r=3*r;
    ll ans=0;

    while(l<=r){
        ll mid=(l+r)/2;
        //cout<<mid<<" "<<f(mid)<<endl;
        if(f(mid)<=k){
            ans=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
