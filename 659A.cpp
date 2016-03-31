#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define T ll t; cin>>t ; while(t--)
#define fin freopen("i1.txt","r",stdin)
#define fout freopen("o1.txt","w",stdout)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pf(n) cout<<n<<endl;
#define pb(x) push_back(x)

int main(){
    //fin;

    ll n,a,b;
    cin>>n>>a>>b;

    a--;

    while(b<0) b+=n;

    ll ans=(a+b)%n;

    cout<<ans+1<<endl;

    return 0;
}
