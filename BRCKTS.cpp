#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(w) do { for(ll f=0;f<10;f++) cout<< w << " " ; cout<<"\n";}while(0);

const ll MAX=30001;
string s;
ll n,q;

struct Node{
    ll uop,ucp;  // unmatched open and closed parenthesis
}segTree[4*MAX+1];

Node makeNode(char c){
    Node temp;
    temp.uop =(c=='('?1:0) ;
    temp.ucp=(c==')'?1:0) ;
    return temp;
}

Node combine(Node L,Node R){
    Node temp;
    ll m=min(L.uop,R.ucp);
    temp.uop=L.uop + R.uop - m;
    temp.ucp=L.ucp + R.ucp - m;
    return temp;
}

Node build(ll i=1,ll l=0,ll r=n-1){
    if(l>r)
        return makeNode('-');
    if(l==r){
        segTree[i]=makeNode(s[l]);
        return segTree[i];
    }
    ll mid=(l+r)>>1;
    Node L=build(2*i,l,mid);
    Node R=build(2*i+1,mid+1,r);
    segTree[i]=combine(L,R);
}

void update(ll idx,ll l=0,ll r=n-1,ll i=1){
    if(l>r)
        return;
    if(l==r && l==idx){
        segTree[i]=makeNode(s[l]);
        return;
    }
    ll mid=(l+r)>>1;
    if(idx<=mid)
        update(idx,l,mid,2*i);
    else
        update(idx,mid+1,r,2*i+1);

    segTree[i]=combine(segTree[2*i],segTree[2*i+1]);
}

int main(){
    //fin;
    for(ll test=1;test<11;test++) {
        cout<<"Test :"<<test<<"\n";
        cin>>n>>s>>q;
        for(ll i=0;i<4*MAX;i++) segTree[i]=makeNode('-');
        build();
        while(q--) {
            ll x;
            cin>>x;
            if(x==0) {
                if(segTree[1].ucp==0 && segTree[1].uop==0) {
                    cout<<"YES"<<endl;
                }
                else {
                    cout<<"NO"<<endl;
                }
            }else {
                x--;
                if(s[x]==')') s[x]='(';
                else s[x]=')';
                update(x);
            }
        }
    }
    return 0;
}
