#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long

deque<ll> q;
deque<ll>::iterator it;

int main(){
    //fin;
    ll n,k;
    cin>>n;

    ll a[n+1];

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>k;

    for(ll i=0;i<k;i++){
        while( !q.empty() && q.front() <= a[i])
            q.pop_front();
        q.push_front(a[i]);
    }

    cout<< q.back() <<" ";

    for(ll i=k;i<n;i++){
        if(!q.empty() && q.back()==a[i-k] )
            q.pop_back();

        while(!q.empty() && q.front()<a[i] )
            q.pop_front();

        q.push_front(a[i]);
        cout<<q.back()<<" ";
    }
    cout<<"\n";

    return 0;
}
