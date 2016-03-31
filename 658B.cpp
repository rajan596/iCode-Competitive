#include<bits/stdc++.h>

using namespace std;

#define ll int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n,k,qq;
    cin>>n>>k>>qq;

    ll t[n+5];

    for(ll i=0;i<n;i++) cin>>t[i];

    priority_queue<ll,vector<ll>,std::greater<ll> > q;
    map<ll,ll> h;

    for(ll i=0;i<qq;i++) {
        ll type,id;
        cin>>type>>id;
        id--;

        if(type==1) {
            if(q.size()<k) {
                q.push(t[id]);
                h[id]=1;
            }
            else{
                if(q.top()<t[id] ) {
                    q.pop();
                    q.push(t[id]);
                    h[id]=1;

                }
            }
        }
        else if(type==2) {
            if(h[id]==1 && q.top()<=t[id]){
                cout<<"YES"<<endl;
            }else {
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
