#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //freopen("i1.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m;
    cin>>n>>m;

    long long p[n],pos[n],z[n];

    for(ll i=0;i<n;i++) {
        cin>>p[i];
        pos[p[i]]=i;
        z[i]=n;
    }

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;

        if(pos[x]>pos[y]){
            ll temp=x;
            x=y;
            y=temp;
        }
        z[pos[x]]=min(z[pos[x]],pos[y]);
    }

    ll ans=0,rg=n;

    for(ll i=n-1;i>=0;i--){
        rg=min(z[i],rg);
        ans+=rg-i;
    }

    cout<<ans<<endl;

    return 0;
}
