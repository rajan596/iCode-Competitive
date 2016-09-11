#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

int main(){

    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;

    ll g=__gcd(a,b);
    g=a*b/g;

    cout<< (p*(n/a) + q*(n/b) - min(p*(n/g) , q*(n/g))) <<endl;

    return 0;
}
