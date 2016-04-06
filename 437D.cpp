#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector< pair<ll , pair<ll,ll> > > edges;  // {  { from , to } , weight }
vector< ll > wt(100005);
ll sz[100005],parent[100005];
ll ans=0;
ll n,m;

void make_set(){
    for(ll i=1;i<=n;i++){
        sz[i]=1;
        parent[i]=i;
    }
}

ll findParent(ll x){
    if(x==parent[x])
        return x;
    return findParent(parent[x]);
}

void merge_sets(ll x,ll y,ll w){
    x=findParent(x);
    y=findParent(y);

    if(x==y)
        return;
    //cout<<">>> "<<x<<" "<<y<<" "<<w<<endl;
    ans+=w*sz[x]*sz[y];

    if(sz[x]>sz[y]){
        parent[y]=x;
        sz[x]+=sz[y];
    }
    else{
        parent[x]=y;
        sz[y]+=sz[x];
    }

}

int main(){

    //freopen("i1.txt","r",stdin);
    cin>>n>>m;

    for(ll i=1;i<=n;i++)
        cin>>wt[i];

    for(ll i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        edges.push_back( make_pair( min(wt[x],wt[y]) , make_pair(x,y) ) );
    }

    sort(edges.begin() , edges.end());
    reverse(edges.begin(),edges.end());

    make_set();

    for(ll i=0;i<m;i++){
        merge_sets(edges[i].second.first , edges[i].second.second , edges[i].first);
    }

    double anss=(double)ans;
    anss/=(double)n;
    anss/=(double)(n-1);
    anss*=2.00;

    cout<<fixed<<setprecision(10)<<anss<<endl;

    return 0;
}
