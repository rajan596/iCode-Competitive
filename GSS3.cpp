#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long

const ll MAX=50001;
ll n;
ll a[MAX];

struct Node{
    ll sum,prefixSum,suffixSum,ans;
};

Node segTree[4*MAX+1];

Node combine(Node l,Node r){
    Node temp;
    temp.sum=l.sum+r.sum;
    temp.prefixSum=max(l.prefixSum,l.sum+r.prefixSum);
    temp.suffixSum=max(r.suffixSum,r.sum+l.suffixSum);
    temp.ans=max( l.suffixSum + r.prefixSum , max(l.ans , r.ans) );
    return temp;
}

Node makeNode(ll value){
    Node temp;
    temp.ans=value;
    temp.sum=value;
    temp.prefixSum=value;
    temp.suffixSum=value;
    return temp;
}

Node build(ll node,ll l,ll r){
    if(l>r)
        return makeNode(INT_MIN);
    if(l==r) {
        segTree[node]=makeNode(a[l]);
        return segTree[node];
    }
    ll mid=(l+r)/2;
    Node nodel=build(2*node,l,mid);
    Node noder=build(2*node+1,mid+1,r);

    segTree[node]=combine(nodel,noder);
    return segTree[node];
}

void update(ll idx,ll value,ll node=1,ll l=0,ll r=n-1){
    //cout<< " >>>  "<<l <<" "<< r << " " <<endl;

    if(l==r && l==idx) {
        segTree[node]=makeNode(value);
        return;
    }

    ll mid=(l+r)/2;

    if(idx<=mid)
        update(idx,value,2*node,l,mid);
    else
        update(idx,value,2*node+1,mid+1,r);

    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
    //cout<< "Update : "<<l <<" "<< r << " "<<segTree[node].sum <<endl;
}

Node query(ll ql,ll qr,ll l,ll r,ll node){
    //cout<< ql <<" "<< qr <<" "<< l <<" "<< r << " "<<segTree[node].ans <<endl;
    // invalid
    if(l>r)
        return makeNode(INT_MIN);
    // out of range
    if(l>qr || r<ql){
        return makeNode(INT_MIN);
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
    fin;
    cin>>n;

    for(ll i=0;i<n;i++)
        cin>>a[i];

    ll q;
    cin>>q;

    build(1,0,n-1);

    while(q--) {
        ll type,x,y;
        cin>>type>>x>>y;

        if(type==1) {
            cout<<query(x-1,y-1,0,n-1,1).ans<<endl;
        }
        else {
            a[x-1]=y;
            update(x-1,y);
        }
    }

    return 0;
}
