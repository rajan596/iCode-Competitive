#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

const ll mod=1e9+7;
map<ll,ll>::iterator it,it1;

int main(){

    vector<ll> v;
    v.push_back(1);
    v.push_back(2);

    for(ll i=2;;i++){
        ll p=v[i-1]+v[i-2];
        if(p>1e9) break;
        v.push_back(p);
    }

    //for(ll i=0;i<v.size();i++)    cout<<i<<" "<<v[i]<<endl;

    ll q;
    cin>>q;

    while(q--){
        ll x,k;
        cin>>x>>k;
    }

    return 0;
}
