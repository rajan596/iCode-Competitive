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
        string w;
        cin>>w;

        ll k;
        cin>>k;

        map<char,ll> mp;

        for(ll i=0;i<w.length();i++) mp[w[i]]++;

        vector<ll> v;

        for(char c='a';c<='z';c++){
            if(mp[c]>0)
                v.push_back(mp[c]);
        }

        sort(v.begin(),v.end());

        vector<ll> pre(v.size(),0);
        pre[0]=v[0];

        for(ll i=1;i<v.size();i++){
                pre[i]=pre[i-1]+v[i];
        }

        ll ans=pre[v.size()-1];
        ll temp=0;

        for(ll i=0;i<v.size();i++){
                ll max_frequency=v[i]+k;
                temp=(i==0?0:pre[i-1]);

                for(ll j=i+1;j<v.size();j++){
                        temp+=max((ll)0, v[j]-max_frequency);
                }

                ans=min(ans,temp);
        }

        cout<<ans<<endl;
    }

    return 0;
}
