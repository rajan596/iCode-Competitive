#include<bits/stdc++.h>

using namespace std;

#define ll int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

vector<ll> graph[100002];
map<ll,ll> visited;
ll ans=0;
ll cycle=0;

void dfs(ll v,ll parent){
    //cout<<">> "<<v<<endl;

    visited[v]=1;

    for(ll i=0;i<graph[v].size();i++){
        ll u=graph[v][i];
        if(u==parent) continue;
        if(visited[u]){
            cycle=1;
            //cout<<"Cycle found"<<endl;
        }else{
            dfs(u,v);
        }
    }
}

int main(){

    //fin;

    ll n,m;
    cin>>n>>m;

    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(ll i=1;i<=n;i++){
        if(!visited[i]) {
            //cout<<":: "<<i<<endl;
            dfs(i,0);
            if(!cycle) ans++;
            cycle=0;
        }
    }

    cout<<ans<<endl;

    return 0;
}
