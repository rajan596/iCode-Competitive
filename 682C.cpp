#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

ll n;
ll a[100005];
vector<ll> v[100005];
ll c[100005];
ll ans=0;
bool visited[100005];
vector<ll> dist[100005];
ll nodes[100005];

ll dfs(ll node,ll distance){
    if(distance > a[node])
        return 0;

    ll ans=1;
    for(ll i=0;i<v[node].size();i++){
        ll x=v[node][i];
        ll y=dist[node][i];
        ans+=dfs(x,max((ll)0,distance+y));
    }
    return ans;
}

int main(){
    fastio;
    fin;

    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<n;i++){
        ll p,ct;
        cin>>p>>ct;
        v[p].push_back(i+1);
        dist[p].push_back(ct);
    }

    cout<<n-dfs(1,0)<<endl;

    return 0;
}
