#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll MAX=500101;

ll pop_now[MAX],pop_was[MAX],from[MAX],to[MAX],road[MAX],A[MAX],B[MAX],ans[MAX],parent[MAX];
string qr[MAX];
set< pair<ll,ll> , greater< pair<ll,ll> > > now;

ll findParent(ll x){
    if(parent[x]==x)
        return x;
    int y=findParent(parent[x]);
    parent[x]=y;
    return y;
}

void merge_set(ll x,ll y){
    ll px=findParent(x);
    ll py=findParent(y);

    if(px==py)
        return;

    now.erase(make_pair(pop_now[px],px));
    now.erase(make_pair(pop_now[py],py));

    if(rand()%2){
        parent[px]=py;
        pop_now[py]+=pop_now[px];
        now.insert(make_pair(pop_now[py],py));
    }
    else{
        parent[py]=px;
        pop_now[px]+=pop_now[py];
        now.insert(make_pair(pop_now[px],px));
    }
}

ll getAns(){
    return (*now.begin()).first;
}

int main(){
    //freopen("i1.txt","r",stdin);

    ll n,m,q;
    cin>>n>>m>>q;

    for(ll i=1;i<=n;i++){
        cin>>pop_now[i];
        parent[i]=i;
    }

    for(ll i=1;i<=m;i++) {
        cin>>from[i]>>to[i];
        road[i]=1;
    }

    for(ll i=1;i<=q;i++){
        cin>>qr[i];

        if(qr[i][0]=='P'){
            ll x,y;
            cin>>x>>y;
            A[i]=x;
            B[i]=y;
            pop_was[i]=pop_now[x];
            pop_now[x]=y;
        }else {
            ll x;
            cin>>x;
            A[i]=x;
            road[x]=0;
        }
    }

    for(ll i=1;i<=n;i++){
        now.insert(make_pair(pop_now[i],i));
    }

    for(ll i=1;i<=m;i++){
        if(road[i]){
            merge_set(from[i],to[i]);
        }
    }

    ans[q]=getAns();

    for(ll i=q;i>0;i--){
        if(qr[i][0]=='D'){
            road[A[i]]=1;
            merge_set(from[A[i]],to[A[i]]);
        }
        else{
            ll x=findParent(A[i]);
            now.erase(make_pair(pop_now[x],x));
            pop_now[x]=pop_now[x] + pop_was[i] - B[i];
            now.insert(make_pair(pop_now[x],x));
        }
        ans[i-1]=getAns();
    }

    for(ll i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
