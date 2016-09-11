#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);


int main(){

    ll n,t;
    cin>>n>>t;

    double mat[n+50][n+50];

    mat[1][1]=t;
    ll ans=0;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(mat[i][j]>=1) {
                ans++;
                double kk=mat[i][j]-1;
                mat[i+1][j]+=kk/2;
                mat[i+1][j+1]+=kk/2;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
