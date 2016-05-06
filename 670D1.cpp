#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

struct node{
    ll index;
    ll no;
    ll need;
};

struct compare {
    bool operator()(node l,node r){
        return l.no > r.no;
    }
};

node make_node(ll i,ll no,ll need){
    node t;
    t.no=no;
    t.need=need;
    t.index=i;
    return t;
}

int main(){

    ll n,k;
    cin>>n>>k;

    ll a[n],b[n],ans[n];
    priority_queue< node , vector<node> , compare> q;


    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        cin>>b[i];
        if(b[i]%a[i]==0)
            q.push(make_node(i,b[i]/a[i]+1,a[i]));
        else
            q.push(make_node(i,b[i]/a[i]+1, a[i]-b[i]%a[i] ));

        ans[i]=b[i]/a[i]+1;
    }

    while(k>0) {
        node x=q.top();
        q.pop();
        //cout<< x.index <<" "<<x.need <<" "<<x.no <<endl;
        if(x.need<=k) {
            k-=x.need;
            q.push(make_node(x.index,x.no+1,a[x.index]));
            ans[x.index]++;
        }
        else
            break;
    }

    ll mx=INT_MAX;
    for(int i=0;i<n;i++) mx=min(mx,ans[i]);

    cout<<mx-1<<endl;

    return 0;
}
