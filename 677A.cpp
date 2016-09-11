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
    ll n,h;
    cin>>n>>h;

    ll ans=0;
    for(ll i=0;i<n;i++){
        ll t;
        cin>>t;

        ans+=ceil((double)t/h);
        //cout<<ceil((double)t/h)<<endl;
    }

    cout<<ans<<endl;

    return 0;
}
