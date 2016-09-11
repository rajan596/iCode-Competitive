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
        string a,b;
        cin>>a>>b;

        ll a0=0,a1=0,b0=0,b1=0,i1=0,i0=0; // i for invalid
        ll n=a.length();

        for(ll i=0;i<n;i++){
            if(a[i]=='0') a0++;
            else a1++;

            if(b[i]=='0') b0++;
            else b1++;

            if(a[i]=='0' && b[i]=='1') i0++;
            if(a[i]=='1' && b[i]=='0') i1++;
        }

        if((b0>0 && a0==0) || (b1>0 && a1==0) ){
            cout<<"Unlucky Chef"<<endl;
            continue;
        }else{
            cout<<"Lucky Chef"<<endl;
        }

        ll ans=0;
        ll x=min(i1,i0);
        ans+=x;
        i1-=x;
        i0-=x;
        ans+=i1+i0;

        cout<<ans<<endl;
    }

    return 0;
}
