#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n,k;
    cin>>n>>k;

    map<ll,ll> mp;

    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        mp[x]=1;
    }

    ll ans=0;
    vector<ll> v;

    for(ll i=1;i<=1000000;i++) {
        if(mp[i]==1) continue;
        else if(k-i>=0){
            ans++;
            k-=i;
            v.push_back(i);
        }else
            break;
    }

    cout<< ans <<endl;

    for(ll i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}
