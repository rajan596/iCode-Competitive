#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long

const ll MAX=110001;
ll n,q;

struct Node{
    ll sum,lazy,lazy2; // lazy2 for assigning [i,j] = v ; lazy to add interval [i,j] by v
};

Node segTree[4*MAX+1];

Node makeNode(ll v){
    Node temp;
    temp.sum=v*v;
    temp.lazy=0;
    temp.lazy2=0;
    return temp;
}

Node combine(Node L,Node R){
    Node temp;
    temp.sum=L.sum+R.sum;
    temp.lazy=0;
    temp.lazy2=0;
    return temp;
}

void update(ll idx,ll idy,ll value,ll node=1,ll l=0,ll r=n-1){
    if(l>r)
        return;
    // previous pending lazy update
    if(segTree[node].lazy!=0) {
        segTree[node].sum+=(r-l+1)*segTree[node].lazy;
        if(l!=r){
            segTree[2*node].lazy+=segTree[node].lazy;
            segTree[2*node+1].lazy+=segTree[node].lazy;
        }
        segTree[node].lazy=0;
    }
    if(l>idy || r<idx)
        return;
    if(idx<=l && r<=idy){
        segTree[node].sum+=(r-l+1)*value;
        if(l!=r){
            segTree[2*node].lazy+=value;
            segTree[2*node+1].lazy+=value;
        }
        return;
    }
    // partial overlap
    ll mid=(l+r)>>1;
    update(idx,idy,value,2*node,l,mid);
    update(idx,idy,value,2*node+1,mid+1,r);
    segTree[node].sum=segTree[2*node].sum+segTree[2*node+1].sum;

}

Node query(ll ql,ll qr,ll l=0,ll r=n-1,ll node=1){

    // invalid
    if(l>r)
        return makeNode();

    // out of range
    if(l>qr || r<ql){
        return makeNode();
    }

    if(segTree[node].lazy!=0) {
        segTree[node].sum+=(r-l+1)*segTree[node].lazy;
        if(l!=r) {
            segTree[2*node].lazy+=segTree[node].lazy;
            segTree[2*node+1].lazy+=segTree[node].lazy;
        }
        segTree[node].lazy=0;
    }

    // complete overlap
    if(ql<=l && r<=qr){
        return segTree[node];
    }

    // partial overlap
    ll mid=(l+r)/2;
    Node L=query(ql,qr,l,mid,2*node);
    Node R=query(ql,qr,mid+1,r,2*node+1);
    return combine(L,R);
}

int main(){
    //fin;

    ll t;
    cin>>t;

    while(t--) {
        cin>>n>>q;
        for(ll i=0;i<4*MAX;i++) segTree[i]=makeNode();
        while(q--) {
            ll type,x,y,z;
            cin>>type;

            if(type==0) {
                cin>>x>>y>>z;
                assignRangeX(x-1,y-1,z);
            }
            else if(type==1){
                cin>>x>>y>>z;
                update(x-1,y-1,z);
            }
            else{
                cin>>x>>y;
                cout<<query(x-1,y-1)<<endl;
            }
        }
    }

    return 0;
}
