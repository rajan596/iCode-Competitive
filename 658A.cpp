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

    ll n,c;
    cin>>n>>c;

    ll p[n+2],ti[n+2];
    for(ll i=0;i<n;i++)
        cin>>p[i];

     for(ll i=0;i<n;i++)
        cin>>ti[i];


    ll l=0,r=0,tt=0;

    for(ll i=0;i<n;i++){
        tt+=ti[i];
        l+=max(0,p[i]-c*tt);
    }

    tt=0;
    for(ll i=n-1;i>=0;i--){
        tt+=ti[i];
        r+=max(0,p[i]-c*tt);
    }

    if(l>r) printf("Limak");
    else if(r>l) printf("Radewoosh");
    else printf("Tie");

    return 0;
}
