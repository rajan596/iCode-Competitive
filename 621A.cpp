#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    //freopen("i1.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;

    vector<ll> odds;
    ll ans=0;

    ll x;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(x%2==0) ans+=x;
        else odds.push_back(x);
    }

    sort(odds.begin(),odds.end());
    reverse(odds.begin(),odds.end());

    for(ll i=1;i<odds.size();i+=2){
        ans+=odds[i-1]+odds[i];
    }

    cout<<ans<<endl;

    return 0;
}
