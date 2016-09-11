#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    map<ll,ll> mp;

    for(ll i=0;i<64;i++){
        for(ll j=0;j<64;j++) {
            mp[i&j]++;
        }
    }

    string s;
    cin>>s;

    ll ans=1;
    ll mod=1e9+7;

    for(ll i=0;i<s.length();i++){
        ll x;
        if(s[i]>='0' && s[i]<='9') x=s[i]-'0';
        else if(s[i]>='A' && s[i]<='Z') x=s[i]-'A'+10;
        else if(s[i]>='a' && s[i]<='z') x=s[i]-'a'+36;
        else if(s[i]=='-') x=62;
        else x=63;

        ll y=mp[x];
        ans=(ans*y)%mod;
    }

    cout<<ans<<endl;

    return 0;
}
