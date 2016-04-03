#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll LU[1002],RU[1002],L[1002],R[1002];

int main(){
    freopen("i1.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;

        if(y-(x-1)>=1) {
            LU[y-(x-1)]++;
        }else{
            L[x-(y-1)]++;
        }

        if(y+(x-1)<=1000) {
            RU[y+(x-1)]++;
        }else{
            R[y+(x-1)-999]++;
        }
    }
    ll ans=0;
    for(ll i=1;i<=1000;i++){
        //cout<<LU[i]<<" "<<RU[i]<<" "<<L[i]<<" "<<R[i]<<endl;
        ans+=(LU[i]-1)*(LU[i])/2  + (RU[i]-1)*(RU[i])/2  + (L[i]-1)*(L[i])/2 + (R[i]-1)*(R[i])/2;
    }

    cout<<ans<<endl;

    return 0;
}
