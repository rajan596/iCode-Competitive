#include<bits/stdc++.h>

using namespace std;

#define fin freopen("i1.txt","r",stdin)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define oo(x) do{ for(int zo=1;zo<=5;zo++) cout<<x; cout<<"\n"; }while(0);

ll a[100005];

int main(){
    fastio;
    //fin;

    ll n;
    cin>>n;

    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(x>n) a[n+1]++;
        else a[x]++;
    }

    ll i=1,j=1;

    while(j<=n+1 && i<=n){
        //cout<<i<<" "<<j<<endl;
        if(a[i]>0){
            i++;
        }
        else {
            if(j<=i) j=i+1;
            while(j<=n+1 && a[j]==0) {
                j++;
            }
            if(j==n+2) {
                cout<<i<<endl;
                return 0;
            }
            else {
                a[i++]++;
                a[j]--;
            }
        }
    }

    if(a[n]==0) cout<<n<<endl;
    else cout<<n+1<<endl;

    return 0;
}
