#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

const ll mod=1e9+7;

ll n,m,s;

int main(){

    ll t;
    cin>>t;

    while(t--) {
        ll s;
        cin>>n>>m>>s;

        ll a[m];
        for(ll i=0;i<m;i++) cin>>a[i];

        ll dp[m+5][n+5];

        for(ll i=0;i<=m;i++){
            for(ll j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }

        dp[m][s]=1;
        ll y=0;
        for(ll i=m-1;i>=0;i--){
            ll x=a[y++];
            for(ll k=1;k<=n;k++){
                ll p=(k-x>=1) ?dp[i+1][k-x]:0;
                ll q=(k+x<=n) ?dp[i+1][k+x]:0;
                dp[i][k]=(p+q)%mod;
            }
        }
        /*
        for(ll i=0;i<=m;i++) {
            for(ll j=1;j<=n;j++) {
                cout<<dp[i][j]<<" ";
            }
            printf("\n");
        }
        */
        for(ll i=1;i<=n;i++)
            cout<<dp[0][i]%mod<<" ";
        printf("\n");
    }

    return 0;
}
