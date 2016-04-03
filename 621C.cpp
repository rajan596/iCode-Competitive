#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //freopen("i1.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,p;
    cin>>n>>p;

    vector< double > good(n+1);

    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;

        good[i]=(double)(y/p-(x-1)/p) / (y-x+1);
    }

    good[n]=good[0];

    double ans=0;

    for(ll i=1;i<=n;i++){
        ans+= 1.0-(1.0-good[i])*(1.0-good[i-1]) ;
    }

    cout<<fixed<<setprecision(12)<<ans*2000.00<<endl;

    return 0;
}
