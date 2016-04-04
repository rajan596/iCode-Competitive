#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll SplitInHalf(ll a[],ll l,ll r){
    if(r<=l)
        return 0;

    if(a[r]-a[l-1]==0)
        return r-l;

    if(r-l==1)
        return a[r]-a[r-1]==a[l]-a[l-1];

    ll L=l,R=r,mid=0;

    while(L<=R) {
        mid=(L+R)/2;
        if(a[mid]-a[l-1]==a[r]-a[mid]){
            //cout<< "mid " <<mid <<endl;
            return 1+max(SplitInHalf(a,l,mid) , SplitInHalf(a,mid+1,r));
        }
        else if(a[mid]-a[l-1] > a[r]-a[mid]){
            R=mid-1;
        }
        else {
            L=mid+1;
        }
    }

    return 0;
}

int main(){
    //freopen("i1.txt","r",stdin);

    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll a[n+2];
        a[0]=0;

        for(ll i=1;i<=n;i++) {
            cin>>a[i];
            a[i]=a[i]+a[i-1];
        }

        a[n+1]=a[0];

        cout<<SplitInHalf(a,1,n)<<endl;
    }

    return 0;
}
