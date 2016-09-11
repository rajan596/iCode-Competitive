#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n,k;
    cin>>n>>k;

    ll y=n%k;
    ll x;
    if(y==0) x=n+k;
    else
        x=n+k-y;

    cout<<x<<endl;

    return 0;
}
