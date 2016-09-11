#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

ll x[1005];

int main(){

    ll n,z;
    cin>>n>>z;

    for(ll i=0;i<n;i++){
        ll a[2];
        cin>>a[0]>>a[1];
        sort(a,a+2);
        x[a[0]]++;
        x[a[1]+1]--;
    }

    for(ll i=1;i<1001;i++){
        x[i]=x[i] + x[i-1];
    }

    ll ans=INT_MAX;
    for(ll i=0;i<=1000;i++){
        if(x[i]==n) ans=min(ans,abs(z-i));
    }

    if(ans==INT_MAX) ans=-1;
    cout<< ans <<endl;

    return 0;
}
