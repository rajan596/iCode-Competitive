#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){
    //fin;
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll a[n];
        bool all_neg=1;
        for(ll i=0;i<n;i++) {
            cin>>a[i];
            if(a[i]>0) all_neg=0;
        }

        if(all_neg) {
            sort(a,a+n);
            cout<<a[n-1]<<endl;
            continue;
        }

        ll pre[n],suf[n];
        ll temp=0;
        ll ans=0;

        for(ll i=0;i<n;i++){
            temp=max((ll)0,temp+a[i]);
            ans=max(ans,temp);
            pre[i]=temp;
        }
        temp=0;

        for(ll i=n-1;i>=0;i--) {
            temp=max((ll)0,temp+a[i]);
            suf[i]=temp;
        }

        for(ll i=0;i<n;i++){
            if(i==0) {
                ans=max(ans,suf[i+1]);
            }
            else if(i==n-1) {
                ans=max(ans,pre[i-1]);
            }
            else
                ans=max(ans,pre[i-1]+suf[i+1]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
