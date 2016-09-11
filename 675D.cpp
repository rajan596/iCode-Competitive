#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n,v;
    cin>>n>>v;

    set<ll> s;
    s.insert(v);
    map<ll,ll> left,right;

    for(ll i=1;i<n;i++){
        cin>>v;
        set<ll>::iterator it;
        it=s.upper_bound(v);
        if(it!=s.end() && left[*it]==0 ) {
            left[*it]=v;
        }else{
            it--;
            right[*it]=v;
        }
        s.insert(v);
        cout<< (*it) <<" ";
    }

    return 0;
}
