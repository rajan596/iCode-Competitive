#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

const ll MAX=1e5+1,mod=1e9+7;

struct Node{
    ll mn,mx,mxno,mnno;
}segTree[4*MAX];

ll a[MAX];
ll n,q;

Node makeNode(ll minval=1e18,ll maxval=-1e18){
    Node temp;
    temp.mn=minval;
    temp.mx=maxval;

    if(minval==INT_MAX)
        temp.mnno=0;
    else
        temp.mnno=1;

    if(maxval==INT_MAX)
        temp.mxno=0;
    else
        temp.mxno=1;

    return temp;
}

Node combine(Node l,Node r){
    Node temp;

    if(l.mn==r.mn){
        temp.mn=l.mn;
        temp.mnno=l.mnno+r.mnno;
    }
    else if(l.mn > r.mn){
        temp.mn=r.mn;
        temp.mnno=r.mnno;
    }
    else {
        temp.mn=l.mn;
        temp.mnno=l.mnno;
    }

    if(l.mx==r.mx){
        temp.mx=l.mx;
        temp.mxno=l.mxno+r.mxno;
    }
    else if(l.mx < r.mx){
        temp.mx=r.mx;
        temp.mxno=r.mxno;
    }
    else {
        temp.mx=l.mx;
        temp.mxno=l.mxno;
    }

    //cout<<"##:## "<<l.mx<<" "<<r.mx<<" "<<temp.mx<<endl;
    return temp;
}

Node build(ll i,ll l,ll r){
    if(l>r) {
        return makeNode();
    }
    if(l==r) {
        segTree[i]=makeNode(a[l],a[l]);
        //cout<< "#)) : "<<l<<" "<<r<<" "<< segTree[i].mx <<" , "<<segTree[i].mn <<endl;
        return segTree[i];
    }
    ll mid=(l+r)>>1;
    Node L=build(2*i,l,mid);
    Node R=build(2*i+1,mid+1,r);
    segTree[i]=combine(L,R);
    return segTree[i];
    //cout<< "# : "<<l<<" "<<r<<" "<< segTree[i].mx <<" , "<<segTree[i].mn <<endl;
}

Node query(ll ql,ll qr,ll l=0,ll r=n-1,ll i=1){
    if(l>r){
        return makeNode();
    }
    if(qr<l || r<ql){
        return makeNode();
    }
    if(ql<=l && r<=qr) {
        return segTree[i];
    }
    ll mid=(l+r)>>1;
    Node L=query(ql,qr,l,mid,2*i);
    Node R=query(ql,qr,mid+1,r,2*i+1);
    return combine(L,R);
}

void update(ll idx,ll i=1,ll l=0,ll r=n-1){
    if(l>r){
        return;
    }
    if(l==r && l==idx) {
        segTree[i]=makeNode(a[l],a[l]);
        return;
    }
    ll mid=(l+r)>>1;
    if(idx<=mid)
        update(idx,2*i,l,mid);
    else
        update(idx,2*i+1,mid+1,r);
    segTree[i]=combine(segTree[2*i],segTree[2*i+1]);
}

int main(){
    //fin;
    cin>>n;

    for(ll i=0;i<n;i++) {
        cin>>a[i];
        a[i]=a[i]%mod;
    }
    build(1,0,n-1);
    cin>>q;

    while(q--) {
        string s;
        ll u,v;
        cin>>s>>u>>v;
        if(s=="MAX") {
            u--,v--;
            Node x=query(u,v);
            cout<<x.mx<<" "<<x.mxno<<endl;
        }
        else if(s=="MIN"){
            u--,v--;
            Node x=query(u,v);
            cout<<x.mx<<" "<<x.mxno<<endl;
        }
        else if(s=="ADD"){
            u--;
            a[u]=(a[u]+v)%mod;
            update(u);
        }
        else if(s=="MUL"){
            u--;
            a[u]=(a[u]*v)%mod;
            update(u);
        }
        else if(s=="REP"){
            u--;
            a[u]=(v)%mod;
            update(u);
        }
    }

    return 0;
}
